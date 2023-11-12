#include "_header.h"

//Template vs Object Function
//Creating a variable type

/*template <typename peepoo>
void Times2(peepoo val){
    cout << val << " * 2 = " << val * 2 << endl;
}*/

template <typename peepoo>
peepoo Add(peepoo val1, peepoo val2){
    return val1 + val2;
}

template <typename waterm>
waterm Max(waterm num1, waterm num2){
    return (num1 > num2) ? num1 : num2;
}

int main(){

    cout << "5 + 4 = " << Add(5, 4) << endl;        //int must have the same datatype
    cout << "5.2 + 4 = " << Add(5.5, 4.2) << endl;  //double 

    cout << "Max: " << Max(5,8) << endl;
    cout << "Max: " << Max('a', 'G') << endl;
    cout << "Max: " << Max("Dog", "Cat") << endl;

    cout << endl;
    return 0;
}
