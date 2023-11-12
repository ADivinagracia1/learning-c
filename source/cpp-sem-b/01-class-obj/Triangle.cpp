#include "Triangle.h"
#include "Shape.h"

                            //INHERITANCE
Triangle::Triangle(double height, double width): Shape(height, width){
}

Triangle::~Triangle() = default;

double Triangle::Area(){
    return 0.5 * width * height;
}