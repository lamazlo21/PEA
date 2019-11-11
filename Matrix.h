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
    // Overloading [] operator to access elements in array style
    int* const &operator[] (int) const;

    Matrix(string);

    ~Matrix();

    string getName();

    int getMatrixSize() const;

    void printMatrix();

    void printShortestPath();

    int pathValue(int*) const;

    int pathValue(vector<int>);

    // Dynamic algorithims

    int dynamic(int, vector<int>);


};

#endif //PEA_MATRIX_H
