#ifndef TRIANGLE_H 
#define TRIANGLE_H
#include "Shape.h"

//INHERITANCE  VVVVVVVVV
class Triangle: public Shape {
public:  
    Triangle(double length, double width);

    Triangle();                   
    Triangle(const Triangle &orig);   
    virtual ~Triangle();

    double Area();

};

#endif