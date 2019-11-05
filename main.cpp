#include <iostream>
#include "Matrix.h"
#include "Tests.h"

int main() {

    /*Tests test;
    char option;
    while (true) {
        std::cout<<"Wybierz opcje: ";
        std::cin>>option;
        switch(option){
            case '1':
                test.testQue();
                break;
            case '2':
                test.testRandom();
                break;
            default:
                break;
        }

    }*/

    Matrix matrix;
    matrix.initializeMatrix("data10.txt");
    std::cout<<matrix.bruteForceSwap()<<std::endl;
    matrix.printShortestPath();

    return 0;
}