#include <memory>
#include "BranchAndBound.h"
#include <bits/stdc++.h>


BranchAndBound::BranchAndBound(const Matrix &matrix) : matrix(matrix) {
    visited = std::make_unique<bool>(matrix.getMatrixSize());
}


// C++ program to solve Traveling Salesman Problem
// using Branch and Bound.
using namespace std;


// Function to copy temporary solution to
// the final solution
void BranchAndBound::copyToFinal(int* curr_path)
{
    solution.clear();
    solution.addNode(curr_path[0], matrix[0][curr_path[0]]);
    for (int i=1; i<matrix.getMatrixSize(); i++)
        solution.addNode(curr_path[i], matrix[curr_path[i-1]][curr_path[i]]);
    solution.addNode(curr_path[0], matrix[curr_path[matrix.getMatrixSize()]][curr_path[0]]);
}

// Function to find the minimum edge cost
// having an end at the vertex i
int BranchAndBound::firstMin(int i)
{
    int min = INT_MAX;
    for (int k=0; k<matrix.getMatrixSize(); k++)
        if (matrix[i][k]<min && i != k)
            min = matrix[i][k];
    return min;
}

// function to find the second minimum edge cost
// having an end at the vertex i
int BranchAndBound::secondMin(int i)
{
    int first = INT_MAX, second = INT_MAX;
    for (int j=0; j<matrix.getMatrixSize(); j++)
    {
        if (i == j)
            continue;

        if (matrix[i][j] <= first)
        {
            second = first;
            first = matrix[i][j];
        }
        else if (matrix[i][j] <= second &&
                 matrix[i][j] != first)
            second = matrix[i][j];
    }
    return second;
}

// function that takes as arguments:
// curr_bound -> lower bound of the root node
// curr_weight-> stores the weight of the path so far
// level-> current level while moving in the search
//         space tree
// curr_path[] -> where the solution is being stored which
//                would later be copied to final_path[]
void BranchAndBound::TSPRec(int curr_bound, int curr_weight,
            int level, int curr_path[])
{
    // base case is when we have reached level N which
    // means we have covered all the nodes once
    if (level==matrix.getMatrixSize())
    {
        // check if there is an edge from last vertex in
        // path back to the first vertex
        if (matrix[curr_path[level-1]][curr_path[0]] != 0)
        {
            // curr_res has the total weight of the
            // solution we got
            int curr_res = curr_weight +
                           matrix[curr_path[level-1]][curr_path[0]];

            // Update final result and final path if
            // current result is better.
            if (curr_res < final_res)
            {
                copyToFinal(curr_path);
                final_res = curr_res;
            }
        }
        return;
    }

    // for any other level iterate for all vertices to
    // build the search space tree recursively
    for (int i=0; i<matrix.getMatrixSize(); i++)
    {
        // Consider next vertex if it is not same (diagonal
        // entry in adjacency matrix.getMatrixSize() and not visited
        // already)
        if (matrix[curr_path[level-1]][i] != 0 &&
            !visited.get()[i])
        {
            int temp = curr_bound;
            curr_weight += matrix[curr_path[level-1]][i];

            // different computation of curr_bound for
            // level 2 from the other levels
            if (level==1)
                curr_bound -= ((firstMin(curr_path[level-1]) +
                                firstMin(i))/2);
            else
                curr_bound -= ((secondMin(curr_path[level-1]) +
                                firstMin(i))/2);

            // curr_bound + curr_weight is the actual lower bound
            // for the node that we have arrived on
            // If current lower bound < final_res, we need to explore
            // the node further
            if (curr_bound + curr_weight < final_res)
            {
                curr_path[level] = i;
                visited.get()[i] = true;

                // call TSPRec for the next level
                TSPRec(curr_bound, curr_weight, level+1,
                       curr_path);
            }

            // Else we have to prune the node by resetting
            // all changes to curr_weight and curr_bound
            curr_weight -= matrix[curr_path[level-1]][i];
            curr_bound = temp;

            // Also reset the visited array
            memset(visited.get(), false, sizeof(bool)*matrix.getMatrixSize());
            for (int j=0; j<=level-1; j++)
                visited.get()[curr_path[j]] = true;
        }
    }
}

Solution BranchAndBound::find() {
    // final_path[] stores the final solution ie, the
    // path of the salesman.
    //int final_path[matrix.getMatrixSize()+1];




    int* curr_path = new int(matrix.getMatrixSize()+1);

    // Calculate initial lower bound for the root node
    // using the formula 1/2 * (sum of first min +
    // second min) for all edges.
    // Also initialize the curr_path and visited array
    int curr_bound = 0;
    memset(curr_path, -1, sizeof(int)*matrix.getMatrixSize()+1);
    memset(visited.get(), 0, sizeof(bool)*matrix.getMatrixSize());

    // Compute initial bound
    for (int i=0; i<matrix.getMatrixSize(); i++)
        curr_bound += (firstMin(i) +
                       secondMin(i));

    // Rounding off the lower bound to an integer
    curr_bound = (curr_bound&1)? curr_bound/2 + 1 :
                 curr_bound/2;

    // We start at vertex 1 so the first vertex
    // in curr_path[] is 0
    visited.get()[0] = true;
    curr_path[0] = 0;

    // Call to TSPRec for curr_weight equal to
    // 0 and level 1
    TSPRec(curr_bound, 0, 1, curr_path);
    
    return Solution();
}

