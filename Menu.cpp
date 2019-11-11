//
// Created by dawid on 11.11.2019.
//

#include "Menu.h"
void Menu::menuMain() {
    string fileName;
    int option;
    cout << "Wpisz nazwe pliku: ";
    cin>>fileName;
    Matrix matrix(fileName);
    do {
        cout << "1. Wyswietl macierz" << endl;
        cout<< "2. Brute Force menu" <<endl;
        cout<< "3. Dynamic menu" <<endl;
        cout<< "4. Branch and Bound menu" <<endl;
        cout<< "5. Zakoncz" <<endl;
        cout<<"Opcja: ";
        cin>>option;
        switch (option) {
            case 1:
                matrix.printMatrix();
                cout<<endl;
                break;
            case 2:
                menuBruteForce(matrix);
                break;
            case 3:
                menuDynamic(matrix);
                break;
            case 4:
                menuBranchnndBound(matrix);
                break;
            case 5:
                break;
            default:
                cout<<"Nie ma takiej opcji!"<<endl;
                break;
        }
    }while(option!=5);
}

void Menu::menuBruteForce(Matrix matrix) {
    BruteForce bf{matrix};
    int option1, option2;
    Solution solution;
    do {
        cout << "Menu" << endl;
        cout << "1. Wykonaj algorytm Brute Force" << endl;
        cout << "2. Zakoncz" << endl;
        cout<<"Opcja: "<<endl;
        cin>>option1;
        switch (option1) {
            case 1:
                solution = bf.bruteForceSwap();
                do {
                    cout << "1. Wyswietl wartosc sciezki" << endl;
                    cout << "2. Wyswietl sciezke" << endl;
                    cout << "3. Zakoncz" << endl;
                    cout<<"Opcja: "<<endl;
                    cin>>option2;
                    switch (option2) {
                        case 1:
                            cout<<solution.value()<<endl;
                            cout<<endl;
                            break;
                        case 2:
                            solution.print();
                            cout<<endl;
                            break;
                        case 3:
                            solution.clear();
                            break;
                        default:
                            cout << "Nie ma takiej opcji!" << endl;
                            break;
                    }
                }while (option2!=3);
                break;
            case 2:
                break;
            default:
                cout << "Nie ma takiej opcji!" << endl;
                break;
        }
    }while (option1!=2);
}

void Menu::menuDynamic(Matrix matrix) {
    Dynamic dynamic{matrix};
    Solution solution{};
    vector<int> path;
    int option1, option2;
    for(int i=0;i<matrix.getMatrixSize();i++)
        path.push_back(i);
    do {
        cout << "Menu" << endl;
        cout << "1. Wykonaj algorytm Dynamic" << endl;
        cout << "2. Zakoncz" << endl;
        cout<<"Opcja: "<<endl;
        cin>>option1;
        switch (option1) {
            case 1:
                solution = dynamic.dynamic(0, path);
                do {
                    cout << "1. Wyswietl wartosc sciezki" << endl;
                    cout << "2. Wyswietl sciezke" << endl;
                    cout << "3. Zakoncz" << endl;
                    cout<<"Opcja: "<<endl;
                    cin>>option2;
                    switch (option2) {
                        case 1:
                            cout<<solution.value()<<endl;
                            cout<<endl;
                            break;
                        case 2:
                            solution.print();
                            cout<<endl;
                            break;
                        case 3:
                            break;
                        default:
                            cout << "Nie ma takiej opcji!" << endl;
                            break;
                    }
                }while (option2!=3);
                    break;
                    case 2:
                        break;
                    default:
                        cout << "Nie ma takiej opcji!" << endl;
                    break;

        }
    }while (option1!=2);
}

void Menu::menuBranchnndBound(Matrix matrix){
    BranchAndBound bnb{matrix};
    Solution solution{};
    int option1, option2;
    do {
        cout << "Menu" << endl;
        cout << "1. Wykonaj algorytm Branch and Bound" << endl;
        cout << "2. Zakoncz" << endl;
        cout<<"Opcja: "<<endl;
        cin>>option1;
        switch (option1) {
            case 1:
                solution = bnb.find();
                do {
                    cout << "1. Wyswietl wartosc sciezki" << endl;
                    cout << "2. Wyswietl sciezke" << endl;
                    cout << "3. Zakoncz" << endl;
                    cout<<"Opcja: "<<endl;
                    cin>>option2;
                    switch (option2) {
                        case 1:
                            cout<<solution.value()<<endl;
                            cout<<endl;
                            break;
                        case 2:
                            solution.print();
                            cout<<endl;
                            break;
                        case 3:
                            break;
                        default:
                            cout << "Nie ma takiej opcji!" << endl;
                            break;
                    }
                    break;
                    case 2:
                        break;
                    default:
                        cout << "Nie ma takiej opcji!" << endl;
                    break;
                }while (option2!=2);
        }
    }while (false);
}