#include "_header.h"

class Box{
public:
    double length, width, breadth;
    string boxString;

    //Default Constructor
    Box(){ 
        length = 1, width = 1, breadth = 1;
    }

    //Constructor
    Box(double l, double w, double b){ 
        length = l, width = w, breadth = b;
    }

    //Unery Operator (changes the "++")
    Box& operator ++ (){
        length++;
        width++;
        breadth++;
        return *this;
    }

    //cout operator
    operator const char*(){
        ostringstream boxStream;
        boxStream << "Box: " << length << ", " << width << ", " << breadth;
        boxString = boxStream.str();
        return boxString.c_str();
    }

    //Changes the "+" operator
    Box operator + (const Box& box2){
        Box boxSum;
        boxSum.length = length + box2.length;
        boxSum.width = width + box2.width;
        boxSum.breadth = breadth + box2.breadth;
        return boxSum;
    }

    //Changes the "==" operator
    bool operator == (const Box& box2){
        return ((length == box2.length) &&
                (width == box2.width) &&
                (breadth == box2.breadth));
    }

};

int main(){

    Box crate(10, 15, 20);
    ++crate;
    cout << crate << endl;

    Box encl(10, 10, 10);
    cout << "Crate + Enclosure = " << crate + encl << endl;

    cout << "Is Crate == Enclosure? " << (crate==encl) << endl; 

    cout << endl;
    return 0;
}