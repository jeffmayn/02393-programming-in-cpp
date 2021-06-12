#ifndef __arithmetic_syntax_trees__
#define __arithmetic_syntax_trees__

using namespace std;

// Type of operation: "Const" represents a constant value (leaf node)
enum NodeType { Const, Add, Mult };

class ArithmeticSyntaxTree {
public:
    // Constructor for leaf nodes (constants)
    ArithmeticSyntaxTree(unsigned int value);

    // Constructor for internal nodes (left + right, or left * right)
    ArithmeticSyntaxTree(NodeType type, ArithmeticSyntaxTree *left, ArithmeticSyntaxTree *right);

    ~ArithmeticSyntaxTree(); // Destructor

    int size();         // Size of the tree
    int height();       // Height of the tree
    int leaves();       // Number of leaves/constants in the tree
    void traversePre(); // Print nodes in pre-order (prefix notation)
    void traverseIn();  // Print nodes in in-order (infix notation)
    
private:
    NodeType type;	 // This is either Const, Add or Multiply
    int value;       // If the node is a leaf (op == Const), this is its value
    ArithmeticSyntaxTree *left;  // Pointer to left sub-expression tree
    ArithmeticSyntaxTree *right; // pointer to right sub-expression tree
};

#endif // __arithmetic_syntax_trees__
