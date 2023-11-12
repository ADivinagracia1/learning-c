#include "Circle.h"
#include "Shape.h"

                            //INHERITANCE
Circle::Circle(double width): Shape(width){
}

Circle::~Circle() = default;

double Circle::Area(){
    return 0.25 * 3.14159 * width * width;
}