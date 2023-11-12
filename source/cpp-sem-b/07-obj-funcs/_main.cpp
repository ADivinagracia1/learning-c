#include "_header.h"

double MulBy2( double num ){
    return num * 2;
}
            //return type
double DoMath(function<double(double)> func, double num){
    return func(num);
}

int main(){

    //auto - functions as variables
    auto times2 = MulBy2;
    cout << "5 * 2 = " << times2(7) << endl;

    cout << endl;
    return 0;
}
