//
// Created by dawid on 05.11.2019.
//
struct node {
    int data;
    node* left;
    node* right;
};
#ifndef PEA_BST_H
#define PEA_BST_H
class BST {



    node* root;

    node* makeEmpty(node* t);

    node* insert(int x, node* t);

    node* findMin(node* t);


    node* findMax(node* t);

    node* remove(int x, node* t);

    void inorder(node* t);
    node* find(node* t, int x);

public:
    BST() ;
    ~BST() ;

    void insert(int x);
    void remove(int x);

    void display();

    void search(int x);
};
#endif //PEA_BST_H
