#ifndef SHAPES_H
#define SHAPES_H

using namespace std;

class Shape {
    public: 
        double h;
        double w;
        double r;
        virtual double area(void){ 
            return h*w; 
        };
        virtual double perimeter(void){
            return h*2 + w*2;
        }   
        double height(void) { return h; };
        double width(void) { return w; };
        double rotate(void) { 
            double t = h;
            h = w;
            w = t;
            return h+w;
        };
};

class Rectangle: public Shape {
    public:
    Rectangle(double height, double width) { 
        this->h = height; 
        this->w = width; 
    };
};

class Square: public Shape {
    public:
    Square(double length) { 
        this->h = length; 
        this->w = length; 
    };
};

class Circle: public Shape {
    public:
    Circle(double radius) { 
        this->h = radius * 2; 
        this->w = radius * 2; 
    };
    double area(void){ 
        return 3.1415 *(h/2)*(h/2); 
    };
    double perimeter(void) { 
        return 3.1415 * h; 
    };
};

#endif