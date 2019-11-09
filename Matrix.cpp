//
// Created by dawid on 09.10.2019.
//

#include <algorithm>
#include "Matrix.h"
#include "fstream"
#include "BST.h"
#include <vector>
#include <limits.h>

// --------------Desctructor-------------------------------------

Matrix::~Matrix() {
    delete [] matrix;
    delete [] shortestPath;
}

// --------------Constructor-------------------------------------

Matrix::Matrix(string fileName) {

    ifstream file;
    file.open("/home/dawid/CLionProjects/PEA/PEA/SMALL/"+fileName, ios::out);
    file >> matrixName;
    file >> matrixSize;
    shortestPath = new int[matrixSize];
    shortestPathValue = 0;
    if(file.is_open()){
        matrix = new int*[matrixSize];
        for(int i=0; i<matrixSize; i++) {
            shortestPath[i] = 0;
            matrix[i] = new int[matrixSize];
            for (int j = 0; j < matrixSize; j++)
                file >> matrix[i][j];
        }
    }
    else{
        cout<<"File cannot be open!"<<endl;
    }
}

// --------------Matrix Print-------------------------------------

void Matrix::printMatrix() {

    for(int i=0; i<matrixSize;i++){
        for(int j=0; j<matrixSize; j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
}

//---------------Shorest Path Print------------------------------

void Matrix::printShortestPath() {
    for (int i = 0; i < matrixSize; i++)
        cout << shortestPath[i] << " ";
    cout << endl;
}
// --------------Matrix Size-------------------------------------

int Matrix::getMatrixSize() {
    return matrixSize;
}

// --------------Matrix Name-------------------------------------

std::string Matrix::getName() {
    return matrixName;
}

// --------------Brute Force BST-------------------------------------
/*int Matrix::bruteForceBST(){
    BST bst;

}*/

// --------------Brute Force Swap-------------------------------------

// --------------Path Value-------------------------------------------

int Matrix::pathValue(int* arr) {

    int min = 0;
    for(int i=0;i<matrixSize-1;i++)
        min+=matrix[arr[i]][arr[i+1]];
    min+=matrix[arr[matrixSize-1]][0];
    return min;

}

int Matrix::pathValue(vector<int> arr) {

    int min = 0;
    for(int i=0;i<arr.size()-1;i++)
        min+=matrix[arr[i]][arr[i+1]];
    min+=matrix[arr[arr.size()-1]][0];
    return min;

}



// -------------Permute--------------------------------------

pair<int*, int> Matrix::bruteForceSwap(){
    int min, c=0, minCandidate;
    int arr[matrixSize];
    int* shortestPath;
    shortestPath = new int[matrixSize];
    for(int i=0;i<getMatrixSize();i++)
        arr[i] = i;
   sort(arr+1, arr+matrixSize);
    do{
        if(c==0) {
            min = pathValue(arr);
            for(int i=0;i<matrixSize;i++)
                shortestPath[i] = arr[i];
            c++;
        }
        else {
            minCandidate = pathValue(arr);
            if (minCandidate < min) {
                min = minCandidate;
                for(int i=0;i<matrixSize;i++)
                    shortestPath[i] = arr[i];
            }
        }
    }while(next_permutation(arr+1, arr+matrixSize));
    return make_pair(shortestPath, min);
}


int Matrix::dynamic(int k, vector<int> s) {
    if (s.empty()) {
        return matrix[k][0];
    }

    int min = INT_MAX;
    for(int i=0;i<s.size();i++){
            int first = s[i];
            s.erase(s.begin() + i);
            int minCandidate = matrix[k][first] + dynamic(first, s);

            if(minCandidate<min) {
                 min = minCandidate;
            }
            s.insert(s.begin(), first);
        }
    return min;
}


