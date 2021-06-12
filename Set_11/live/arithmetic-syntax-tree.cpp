#include <algorithm>
#include <iostream>

#include "arithmetic-syntax-trees.h"

using namespace std;

// Constructor for leaf nodes (constants)
ArithmeticSyntaxTree::ArithmeticSyntaxTree(unsigned int value) {
    this->type = Const;
    this->value = value;
    this->left = nullptr;
    this->right = nullptr;
}

// Constructor for internal nodes (left + right, or left * right)
ArithmeticSyntaxTree::ArithmeticSyntaxTree(NodeType type,
                                           ArithmeticSyntaxTree *left,
                                           ArithmeticSyntaxTree *right) {
    this->type = type;
    this->value = 0;
    this->left = left;
    this->right = right;
}

// Destructor
ArithmeticSyntaxTree::~ArithmeticSyntaxTree() {
    if (this->left != nullptr) {
        delete this->left;
    }
    if (this->right != nullptr) {
        delete this->right;
    }
}

int ArithmeticSyntaxTree::size(void) {
    switch (this->type) {
    case Const:
        // The size of a constant node is 1
        return 1;
    case Add:
    case Mult:
        // The size of a compound expression is 1 + size of descendent trees
        return 1 + this->left->size() + this->right->size(); 
    default:
        cout << "BUG! This should not happen!" << endl;
        return -1;
    }
}

int ArithmeticSyntaxTree::height(void) {
    switch (this->type) {
    case Const:
        // The height of a constant node is 1
        return 1;
    case Add:
    case Mult:
        // The height of a compound expression is 1 + max height of descendants
        return 1 + max(this->left->height(), this->right->height());
    default:
        cout << "BUG! This should not happen!" << endl;
        return -1;
    }
}

// The number of leaves can be computed in a similar fashion to
// size() and height()
int ArithmeticSyntaxTree::leaves(void) {
    switch (this->type) {
    case Const:
        // The number of leaves of a constant node is 1
        return 1;
    case Add:
    case Mult:
        // The leaves of a compound expression is the sum of descendants leaves
        return this->left->leaves() + this->right->leaves();
    default:
        cout << "BUG! This should not happen!" << endl;
        return -1;
    }
}

// Methods that implement the two (pre-order, in-order) traversal methods
void ArithmeticSyntaxTree::traversePre(void) {
    switch (this->type) {
    case Const:
        cout << this->value;
        return;
    case Add:
        cout << " + ";
        break;
    case Mult:
        cout << " * ";
        break;
    default:
        cout << "BUG! This should not happen!" << endl;
        return;
    }

    cout << "(";
    this->left->traversePre();
    cout << ",";
    this->right->traversePre();
    cout << ")";
}

void ArithmeticSyntaxTree::traverseIn(void) {
    if (this->type == Const) {
        cout << this->value;
        return;
    }

    cout << "(";
    this->left->traverseIn();
    cout << ")";

    switch (this->type) {
    case Add:
        cout << " + ";
        break;
    case Mult:
        cout << " * ";
        break;
    default:
        cout << "BUG! This should not happen!" << endl;
        return;
    }

    cout << "(";
    this->right->traverseIn();
    cout << ")";
}
