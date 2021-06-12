#ifndef FRACTION_H_
#define FRACTION_H_

#include <string>

using namespace std;

class fraction {
    private:
        // Internal representation of a fraction as two integers
        int numerator;
        int denominator;
    public:
        // Class constructor
        fraction(int n, int d);
        // Methods to update the fraction
        void add(fraction f);
        void mult(fraction f);
        void div(fraction f);
        
        // Display method
        void display(void);
};

#endif