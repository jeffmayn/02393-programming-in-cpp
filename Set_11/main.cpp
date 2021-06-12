#include <iostream>

#include "fibonacci-trees.h"

int main() {
    int x;
    cin >> x; 

    FibonacciTree *one;
    one = new FibonacciTree(x);
    FibonacciTree *root = one;


    cout << "Call tree in pre-order: ";
    root->traversePre();
    cout << endl;
    cout << "Call tree size: " << root->size() << endl;
    cout << "Call tree depth: " << root->depth() << endl;
    cout << "Call tree leafs: " << root->leafs() << endl;
    

    return 0;
}