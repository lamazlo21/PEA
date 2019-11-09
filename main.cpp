#include <iostream>
#include "Matrix.h"
#include "Tests.h"
#include <vector>
#include <iostream>

using namespace::std;

int main() {

    Matrix matrix("data3.txt");
    vector<int> x;
    for(int i=1;i<matrix.getMatrixSize();i++){
        x.push_back(i);
    }
    pair<int*, int> bfPair = matrix.bruteForceSwap();
    cout<<"Algorytm BF:"<<endl;
    cout<<"Wartosc najkrotszej sciezki: "<<bfPair.second<<endl;
    cout<<"Najkrotsza sciezka: ";
    for(int i=0;i<matrix.getMatrixSize();i++)
        cout<<bfPair.first[i]<<" ";
    cout<<endl;
    int dynamicMin = matrix.dynamic(0, x);
    cout<<"Algorytm Dynamiczny:"<<endl;
    cout<<"Wartosc najkrotszej sciezki: "<<dynamicMin<<endl;
    cout<<"Najkrotszej sciezka: ";
    matrix.printShortestPath();
    return 0;
}