//
// Created by dawid on 18.10.2019.
//

#include "Tests.h"
#include "iostream"


void Tests::testQue() {
    char option1;
    do{
        char option;
        std::string fileName;
        std::cout<<"Podaj nazwe pliku, ktory chcesz wczytac: ";
        std::cin>>fileName;
        matrix.initializeMatrix(fileName);
        do{
            std::cout<<"Jaką operacje chcesz wykonac?"<<std::endl;
            std::cout<<"1. Wyswietl macierz"<<std::endl;
            std::cout<<"2. Wyświetl wartość funkcji celu"<<std::endl;
            std::cout<<"3. Zakończ"<<std::endl;
            std::cin>>option;
            switch(option){
                case '1':
                        matrix.printMatrix();
                    break;
                case '2':
                    //std::cout<<matrix.findMin(matrix.getMatrixSize())<<std::endl;
                    break;
                case '3':
                    break;
                default:
                    std::cout<<"Nie ma takiej opcji!"<<std::endl;
                    break;
            }
        }while(option!='3');
        std::cout<<"Czy chcesz zakonczyc?"<<std::endl;
        std::cout<<"1. Nie"<<std::endl;
        std::cout<<"2. Tak"<<std::endl;
        std::cin>>option1;
    }while(option1=='1');
}

void Tests::testRandom() {
    std::srand(time(NULL));
    char option1;
    do{
        char option;
        std::string fileName;
        std::cout<<"Podaj nazwe pliku, ktory chcesz wczytac: ";
        std::cin>>fileName;
        matrix.initializeMatrix(fileName);
        int tempArr[matrix.getMatrixSize()];
        for(int i=0;i<matrix.getMatrixSize();i++){
            tempArr[i] = i;
        }

        do{
            std::cout<<"Jaką operacje chcesz wykonac?"<<std::endl;
            std::cout<<"1. Wyswietl macierz"<<std::endl;
            std::cout<<"2. Wyświetl wartość funkcji celu"<<std::endl;
            std::cout<<"3. Zakończ"<<std::endl;
            std::cin>>option;
            switch(option){
                case '1':
                    matrix.printMatrix();
                    break;
                case '2':
                  //  std::cout<<matrix.findMin(tempArr, matrix.getMatrixSize())<<std::endl;
                    break;
                case '3':
                    break;
                default:
                    std::cout<<"Nie ma takiej opcji!"<<std::endl;
                    break;
            }
        }while(option!='3');
        std::cout<<"Czy chcesz zakonczyc?"<<std::endl;
        std::cout<<"1. Nie"<<std::endl;
        std::cout<<"2. Tak"<<std::endl;
        std::cin>>option1;
    }while(option1=='1');
}


