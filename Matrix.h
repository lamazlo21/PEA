//
// Created by dawid on 09.10.2019.
//

#ifndef PEA_MATRIX_H
#define PEA_MATRIX_H
#include <vector>
#include <string>
#include <iostream>

using namespace::std;

class Matrix{

    string matrixName;

    int matrixSize;

    int** matrix;

    int* path;

    int* shortestPath;

    int shortestPathValue;

public:

    Matrix(string);

    ~Matrix();

    string getName();

    int getMatrixSize() const;

    void printMatrix();

    void printShortestPath();

    int pathValue(int*) const;

    int pathValue(vector<int>);

    // Accurate algorithims

    pair<int*, int> bruteForceBST();

    pair<int*, int> bruteForceSwap();

    // Dynamic algorithims

    int dynamic(int, vector<int>);


};

#endif //PEA_MATRIX_H
