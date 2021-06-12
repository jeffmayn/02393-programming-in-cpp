#ifndef __fibonacci_trees__
#define __fibonacci_trees__

using namespace std;

class FibonacciTree {
    public:
        FibonacciTree(unsigned int value);
        FibonacciTree(FibonacciTree *left, FibonacciTree *right);
        ~FibonacciTree();

        int size();
        int depth();
        int leafs();
        void traversePre();

    private:
        int value;
        FibonacciTree *left;
        FibonacciTree *right; 
};


#endif