#include <iostream>
using namespace std;


int main(){

    char inpOp;
    int num1, num2;

    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    cout << "What operation would you like to do? +, -, *, /, %" << endl;
    do{
        cout << "Input an operation: ";
        cin >> inpOp;
        if(inpOp == '+' ){
            cout << "Ans: " << num1 + num2 << endl; break;
        }else if (inpOp == '-'){
            cout << "Ans: " << num1 - num2 << endl; break;
        }else if (inpOp == '*'){
            cout << "Ans: " << num1 * num2 << endl; break;
        }else if (inpOp == '/'){
            cout << "Ans: " << num1 / num2 << endl; break;
        }else if (inpOp == '%'){
            cout << "Ans: " << num1 % num2 << endl; break;
        }
        
    } while (inpOp != '+' || inpOp != '-' || inpOp != '*' ||
             inpOp != '/' || inpOp != '%' );


    cout << endl;
    return 0;

}
