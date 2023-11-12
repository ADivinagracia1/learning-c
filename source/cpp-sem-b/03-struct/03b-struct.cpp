#include "_header.h"
//#include "Shape.h"

//Class  = real world objects
//       = Has public, private, and protectedf
//Struct = data type (variable)
//       = Always Public

struct Shape{
//default is public
    double length, width;

    Shape(double l = 1, double w = 1){
        length = l;
        width = w;
    }

    double Area(){
        return length*width;
    }

private:
    int id;

};

//Inheriting Structs
struct Circle : Shape {
    
    Circle(double w){
        this->width = w;
    }

    double Area(){
        return 3.14159 * 0.25 * width * width;
    }

};

int main(){

    Shape sqr(10, 10);
    cout << "Area:\t" << sqr.Area() << endl;

    Circle circl(5);
    cout << "Area:\t" << circl.Area() << endl;
    /*
    //Aggregate
    Shape rect{10, 5};
    cout << "Area:\t" << rect.Area() << endl;
    */
    cout << endl;
    return 0;
    
}