#include "_header.h"
#include "Shape.h"
#include "Circle.h"
#include "Triangle.h"

void ShowArea(Shape& shaep);

int main(){

    Shape rect(10, 5);
    Circle circl(10);
    Triangle triag(10, 5);

    ShowArea(rect);
    ShowArea(circl);
    ShowArea(triag);

    cout << endl;
    return 0;
}

//Polymorphism VVV = Accepts anything from Shape subclass
void ShowArea(Shape &shaep){
    cout << "Area:\t" << shaep.Area() << endl;
}
