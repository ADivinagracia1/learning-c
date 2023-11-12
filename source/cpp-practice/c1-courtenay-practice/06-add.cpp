#include <iostream>
#include <string>
using namespace std;

int AddTo(int n){

    if(n <= 0)
        return 0;
    else
        return n + AddTo(n-1);
        
}

int main(){

    int num;
    cout << "Choose a number to add to: ";
    cin >> num;

    cout << "The numbers that add to " << num << " is " << AddTo(num) << endl;

    cout << endl;
    return 0;
}