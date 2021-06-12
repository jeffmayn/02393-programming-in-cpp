//============================================================================
// Name        : test.cpp
// Description : Representing arithmetic expressions using trees
//============================================================================
#include <iostream>

#include "arithmetic-syntax-trees.h"

int main() {
    // We want to represent the expression:  ((2 * 3) + (4 * 5)) + 1
    //
    //               +          // Leftmost "+" (called add2 below)
    //          /         \
    //         +	        1   // Rightmost "+" (called add1 below)
    //      /     \
    //    *         *           // Multiplications (called mult1, mult2 below)
    //  /   \      /  \
    // 2     3    4     5

    ArithmeticSyntaxTree *one, *two, *three, *four, *five;
    ArithmeticSyntaxTree *add1, *add2, *mult1, *mult2;

    one = new ArithmeticSyntaxTree(1);
    two = new ArithmeticSyntaxTree(2);
    three = new ArithmeticSyntaxTree(3);
    four = new ArithmeticSyntaxTree(4);
    five = new ArithmeticSyntaxTree(5);
    
    mult1 = new ArithmeticSyntaxTree(Mult, two, three);
    mult2 = new ArithmeticSyntaxTree(Mult, four, five);
    add1 = new ArithmeticSyntaxTree(Add, mult1, mult2);
    add2 = new ArithmeticSyntaxTree(Add, add1, one);

    ArithmeticSyntaxTree *root = add2;

    cout << "The size of the tree is: " << root->size() << endl;
    cout << "The height of the tree is: " << root->height() << endl;
    cout << "The number of leaves of the tree is: " << root->leaves() << endl;
    
    cout << endl << "Representation in prefix notation:" << endl;
    root->traversePre();
    cout << endl;

    cout << endl << "Representation in infix notation:" << endl;
    root->traverseIn();
    cout << endl;

    return 0;
}
