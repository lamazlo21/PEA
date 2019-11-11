//
// Created by shiro on 09.11.19.
//

#include <algorithm>
#include "BruteForce.h"
#include "Solution.h"

BruteForce::BruteForce(const Matrix &matrix) : matrix(matrix), solution(matrix.getMatrixSize()+1)  {

}

void BruteForce::bruteForceSwap(){
    int min, c=0, minCandidate;
    int* arr = new int(matrix.getMatrixSize());
    for(int i=0;i<matrix.getMatrixSize();i++)
        arr[i] = i;
    sort(arr+1, arr+matrix.getMatrixSize());
    do{
        if(c==0) {
            min = matrix.pathValue(arr);
            for(int i=0;i<matrix.getMatrixSize();i++)
                solution.addNode(arr[i]);
            solution.setValue(min);
            c++;
        }
        else {
            minCandidate = matrix.pathValue(arr);
            if (minCandidate < min) {
                min = minCandidate;
                solution.clear();
                for(int i=0;i<matrix.getMatrixSize();i++) {
                    solution.addNode(arr[i]);
                solution.setValue(min);
                }

            }
        }
    }while(next_permutation(arr+1, arr+matrix.getMatrixSize()));
}

