#include <iostream>
#include <string>
using namespace std;

int main(){

    int num1, num2;
    string TorF = "Divisible: ";

    cout << "Enter 2 Nums: ";
    cin >> num1 >> num2;
    TorF += (num1%num2 == 0) ? "true" : "false";
    cout << TorF << endl;

    cout << endl;
    return 0;
}