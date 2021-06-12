#include <algorithm>
#include <iostream>

#include "fibonacci-trees.h"

using namespace std;

FibonacciTree::FibonacciTree(unsigned int value) {

    if((value == 0) || (value == 1)){
        this->value = 1;
        this->left = nullptr;
        this->right = nullptr;
    } else {
        this->left = new FibonacciTree(value-1);
        this->right = new FibonacciTree(value-2);
        this->value = left->value + right->value;  
    }
}

FibonacciTree::FibonacciTree(FibonacciTree *left, FibonacciTree *right) {
    this->left = left;
    this->right = right;
}

void FibonacciTree::traversePre(void){

    if(this->left == nullptr || this->right == nullptr){
        cout << this->value << " ";
        return;
    } else {
        cout << this->value << " ";
        this->left->traversePre();
        this->right->traversePre();
    }
}

int FibonacciTree::depth(void){
    if(this->left == nullptr || this->right == nullptr){
        return 1;
    } else {
        return 1 + max(this->left->depth(), this->right->depth());
    }
}

int FibonacciTree::leafs(void){
    if(this->left == nullptr || this->right == nullptr){
        return 1;
    } else {
        return this->left->leafs() + this->right->leafs();
    }
}

int FibonacciTree::size(void){
    if(this->left == nullptr || this->right == nullptr){
        return 1;
    } else {
        return 1 + left->size() + right->size();
    }
    
}