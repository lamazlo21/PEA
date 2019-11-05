//
// Created by dawid on 09.10.2019.
//

#ifndef PEA_MATRIX_H
#define PEA_MATRIX_H

#include <string>

class Matrix{
    std::string matrixName;
    int matrixSize;
    int** matrix;
    int* shortestPath;
public:

    ~Matrix();

    void initializeMatrix(std::string fileName);

    void printMatrix();

    void printShortestPath();

    std::string getName();

    int getMatrixSize();

    int pathValue(int arr[], int len);

    void permute(int arr[],int begin, int len, int &min);

    // Accurate algorithims

    int bruteForceBST();

    int bruteForceSwap();


};

#endif //PEA_MATRIX_H
