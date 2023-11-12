#include "header.h"

int main(){

    mathCompare();
    //mathOperation();

    std::cout << std::endl;
    return 0;
}

void mathCompare(){

    cout << "abs(-10)\t= " << abs(-10) << endl;
    cout << "max(5, 4)\t= " << max(5, 4) << endl;
    cout << "min(5, 4)\t= " << min(5, 4) << endl;
    cout << "fmax(5.3, 4.3)\t= " << fmax(5.3, 4.3) << endl;
    cout << "fmin(5.3, 4.3)\t= " << fmin(5.3, 4.3) << endl;
    cout << "ceil(10.45)\t= " << ceil(10.45) << endl;
    cout << "floor(10.45)\t= " << floor(10.45) << endl;
    cout << "round(10.45)\t= " << round(10.45) << endl;

}

void mathOperation(){

    cout << "sqrt(100)\t= " << sqrt(100) << endl;
    cout << "cbrt(1000)\t= " << cbrt(1000) << endl;

    //2 ^ 3
    cout << "pow(2,3) = 2^3\t= " << pow(2,3) << endl;
 
    // e ^ x
    cout << "exp(1)   = e^x\t= " << exp(1) << endl;
 
    // 2 ^ x
    cout << "exp2(1)  = 2^x\t= " << exp2(1) << endl;
 
    // e * e * e ~= 20 so log(20.079) ~= 3
    cout << "log(20.079)\t= " << log(20.079) << endl;
 
    // 2 * 2 * 2 = 8
    cout << "log2(8)\t\t= " << log2(8) << endl;
 
    // Hypotenuse : SQRT(A^2 + B^2)
    cout << "hypot(2,3)\t= " << hypot(2,3) << endl;
 
    // Also sin, cos, tan, asin, acos, atan, atan2,
    // sinh, cosh, tanh, asinh, acosh, atanh

}