#ifndef SHAPES_H
#define SHAPES_H

#include <string>

using namespace std;

class Shape {
    public: 
        double h;
        double w;
};

class Retangle: public Shape {
    
};

class Square: public Retangle {
    public: int z;
};

class Circle: public Shape {
    public: int z;
};


#endif