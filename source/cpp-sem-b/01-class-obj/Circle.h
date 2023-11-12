#ifndef CIRLCE_H 
#define CIRCLE_H
#include "Shape.h"

//INHERITANCE  VVVVVVVVV
class Circle: public Shape {
public:  
    Circle(double width);

    Circle();                   
    Circle(const Circle &orig);   
    virtual ~Circle();

    double Area();

};

#endif