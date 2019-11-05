//
// Created by dawid on 09.10.2019.
//

#include <algorithm>
#include "Matrix.h"
#include "fstream"
#include "iostream"
#include "BST.h"

int pathValue(int** matrix, int arr[], int len) {
    int min = 0;
    for(int i=0;i<len-1;i++)
        min+=matrix[arr[i]][arr[i+1]];
    min+=matrix[arr[len-1]][0];
    return min;
}

void permute(int** matrix, int arr[],int begin, int len, int &min, int *shortestPath){
    if(begin==len-1) {
        int temp = pathValue(matrix, arr, len);
        if(temp < min) {
            min = temp;
            for(int i=0;i<len;i++)
                shortestPath[i] = arr[i];
        }
    }
    else{
        for(int i=begin; i<len;i++){
            std::swap(arr[begin],arr[i]);

            permute(matrix, arr,begin+1,len, min, shortestPath);

            std::swap(arr[begin], arr[i]);
        }
    }
}

// --------------Desctructor-------------------------------------

Matrix::~Matrix() {
    delete [] this->matrix;
    delete [] this->shortestPath;
}

// --------------Matrix initialize-------------------------------------

void Matrix::initializeMatrix(std::string fileName) {

    this->matrixSize;
    std::ifstream file;
    file.open("/home/dawid/CLionProjects/PEA/PEA/SMALL/"+fileName, std::ios::out);
    file >> this -> matrixName;
    file >> this->matrixSize;
    if(file.is_open()){
        this->matrix = new int*[this->matrixSize];
        for(int i=0; i<this->matrixSize; i++) {
            this->matrix[i] = new int[this->matrixSize];
            for (int j = 0; j < this->matrixSize; j++)
                file >> this->matrix[i][j];
        }
    }
    else{
        std::cout<<"File cannot be open!"<<std::endl;
    }
    this->shortestPath = new int[this->matrixSize];
}

// --------------Matrix Print-------------------------------------

void Matrix::printMatrix() {
    for(int i=0; i<this->matrixSize;i++){
        for(int j=0; j<this->matrixSize; j++)
            std::cout<<this->matrix[i][j]<<" ";
        std::cout<<std::endl;
    }
}

// --------------Shortest Path-------------------------------------

void Matrix::printShortestPath(){
        for(int i=0; i<this->matrixSize;i++)
            std::cout<<this->shortestPath[i]<<" ";
        std::cout<<std::endl;
};

// --------------Matrix Size-------------------------------------

int Matrix::getMatrixSize() {
    return this->matrixSize;
}

// --------------Matrix Name-------------------------------------

std::string Matrix::getName() {
    return this->matrixName;
}

// --------------Brute Force BST-------------------------------------

int bruteForceBST(){
    BST bst;

}

// --------------Brute Force Swap-------------------------------------

int Matrix::bruteForceSwap(){
    int tempArr[this->getMatrixSize()];
    for(int i=0;i<this->getMatrixSize();i++)
        tempArr[i] = i;
    int min = ::pathValue(this->matrix, tempArr, this->getMatrixSize());
    ::permute(this->matrix, tempArr, 1, this->getMatrixSize(),min, this->shortestPath);
    return min;
}

