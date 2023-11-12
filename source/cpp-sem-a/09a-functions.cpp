#include "header.h"
using namespace std;

int main(){

    printf("%.1f + %.1f = %.1f\n", 5.2, 4.7, AddNumbers(5.2, 4.7));

    //------------------------------------------------------------------

    int age43 = 43;
    age43 = AssignAge(age43);
    cout << "age43 = " << age43 << endl;

    std::cout << std::endl;
    return 0;
}


double AddNumbers(double num1, double num2){
    return num1 + num2;
}

int AssignAge(int age){
    age = 24;
    return age;
}
