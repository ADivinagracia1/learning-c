#include <iostream>
#include <string>
using namespace std;

int Factorial(int n){

    if(n <= 0)
        return 1;
    else
        return n * Factorial(n-1);
        
}

int main(){

    int num;
    cout << "Choose a factorial: ";
    cin >> num;

    cout << num << "! = " << Factorial(num) << endl;

    cout << endl;
    return 0;
}