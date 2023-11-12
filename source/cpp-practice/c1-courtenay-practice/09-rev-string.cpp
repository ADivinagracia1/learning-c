#include <iostream>
#include <string>
using namespace std;

int main(){

    string inp;

    cout << "Enter a string:\t";
    cin >> inp;
    int a = inp.size();

    cout << "Reverse string:\t";
    for(int i = 0; i < inp.size(); i++){
        cout << inp[a - 1 - i];
    }

    cout << endl;
    return 0;
}