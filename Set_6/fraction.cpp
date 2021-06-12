#include "fraction.h"
#include <iostream>
#include<vector>

using namespace std;

int gcd(int a, int b){ 
if (a == 0) 
    return b; 
return gcd(b % a, a); 
} 

vector<int> reduceFraction(int a, int b){
    vector<int> vect;
    int common = gcd(a,b);
    vect.push_back(a/= common);
    vect.push_back(b/= common);

    return vect;
}

fraction::fraction(int num, int den){
    this->numerator = num;
    this->denominator = den;
}

void fraction::div(fraction f){
    vector<int> vect = reduceFraction(this->numerator * f.denominator,  this->denominator * f.numerator);
    this->numerator = vect[0];
    this->denominator =  vect[1];
}

void fraction::mult(fraction f){   
    vector<int> vect = reduceFraction(this->numerator * f.numerator,  this->denominator * f.denominator);
    this->numerator = vect[0];
    this->denominator =  vect[1];
}

void fraction::add(fraction f){
    // if denominators are the same
    if(this->denominator == f.denominator){
        vector<int> vect = reduceFraction(this->numerator = this->numerator + f.numerator, f.denominator);
        this->numerator = vect[0];
        this->denominator =  vect[1];

    // if they are different
    } else {
        int greatest = gcd(this->denominator, f.denominator);
        greatest = (this->denominator * f.denominator) / greatest; 
        int temp = (this->numerator) * (greatest / this->denominator) + (f.numerator) * (greatest / f.denominator);

        vector<int> vect = reduceFraction(temp, greatest);
        this->numerator = vect[0];
        this->denominator =  vect[1];
    }
}

void fraction::display() {
    cout << this->numerator << " / " << this->denominator << endl;
}