#include "_header.h"

//Macros replaces the defined names to the values 
// --> This does not store values in RAM like variables do (think Global vs Macros)
#define PI 3.14159
#define AREA_CIRCLE(radius) (PI * radius * radius)

int main(){

    cout << "Circle area: " << AREA_CIRCLE(2) << endl;

    cout << endl;
    return 0;
}
