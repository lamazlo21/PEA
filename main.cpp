#include <iostream>
#include "Matrix.h"
#include "Tests.h"
#include "BruteForce.h"
#include <vector>
#include <iostream>

using namespace::std;

int main() {

    Matrix matrix("data3.txt");
    vector<int> x;
    for(int i=1;i<matrix.getMatrixSize();i++){
        x.push_back(i);
    }
    BruteForce force{matrix};
    auto sol = force.bruteForceSwap();
    cout<<"Algorytm BF:"<<endl;
    cout<<"Wartosc najkrotszej sciezki: "<<sol.value()<<endl;
    cout<<"Najkrotsza sciezka: ";
    sol.print();

    cout<<endl;
    int dynamicMin = matrix.dynamic(0, x);
    cout<<"Algorytm Dynamiczny:"<<endl;
    cout<<"Wartosc najkrotszej sciezki: "<<dynamicMin<<endl;
    cout<<"Najkrotszej sciezka: ";
    matrix.printShortestPath();
    return 0;
}