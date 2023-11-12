#ifndef SHAPE_H 
#define SHAPE_H

//Class (List all Attributes)

class Shape {
protected:  //Accessible inside the class and inherited classes 
    double height;
    double width;

public:     //Accessible to anything that called the Shape class   
    static int numOfShapes;     //Static = Same value for every class
    Shape(double length);
    Shape(double height, double width);
    Shape();                    //<--- Constructor
    Shape(const Shape &orig);   //<--- Deconstructor
    virtual ~Shape();
    
    void SetHeight(double height);
    double GetHeight();
    void SetWidth(double width);
    double GetWidth();
    static int GetNumOfShapes();    //Access static vars need static methods                    
    
    virtual double Area();          //Virtual = provide each shape to have a different area function

private:    //Accessible only within this Shape class code

};

#endif