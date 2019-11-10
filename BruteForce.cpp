//
// Created by shiro on 09.11.19.
//

#include <algorithm>
#include "BruteForce.h"
#include "Solution.h"

BruteForce::BruteForce(const Matrix &matrix) : matrix(matrix) {

}

Solution BruteForce::bruteForceSwap(){
    int min, c=0, minCandidate;
    int arr[matrix.getMatrixSize()];
    Solution solution{};
    for(int i=0;i<matrix.getMatrixSize();i++)
        arr[i] = i;
    sort(arr+1, arr+matrix.getMatrixSize());
    do{
        if(c==0) {
            min = matrix.pathValue(arr);
            for(int i=0;i<matrix.getMatrixSize();i++)
                solution.addNode(arr[i], min);
            c++;
        }
        else {
            minCandidate = matrix.pathValue(arr);
            if (minCandidate < min) {
                min = minCandidate;
                for(int i=0;i<matrix.getMatrixSize();i++)
                    solution.addNode(arr[i], min);
            }
        }
    }while(next_permutation(arr+1, arr+matrix.getMatrixSize()));
    return std::move(solution);
}

