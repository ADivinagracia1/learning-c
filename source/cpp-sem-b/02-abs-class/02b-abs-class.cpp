#include "_header.h"

//Abstract Class
class Shape{
protected:
    double height;
    double width;
public:
    
    Shape() = default;

    Shape(double h, double w){
        height = h;
        width  = w;
    }

    virtual double Area(){
        return height * width;
    }

};

//Abstract Inheritance
class Circle: public Shape{
protected:
    double width;
public:
    Circle(double w){
        width = w;
    }
    double Area() override{
        return 3.14159 * 0.25 * width * width;
    }
};

//Main------------------------------------------------------------

void ShowArea(Shape &shap);

int main(){

    Shape rect(10, 5);
    Circle circl(10);
    ShowArea(rect);
    ShowArea(circl);

    cout << endl;
    return 0;
}

void ShowArea(Shape &shap){
    cout << "Area:\t" << shap.Area() << endl;
}