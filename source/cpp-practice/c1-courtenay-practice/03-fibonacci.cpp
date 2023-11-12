#include <iostream>
#include <vector>
using namespace std;

double fib1(int n){
//supports 1000+ nums

    double a = 0, b = 1, c;

    if(n <= 1)
        return a;
    else if(n > 2){
        //cout << "fib[0] = " << a << endl;
        for(int i = 2; i < n; i ++){
            c = a + b;
            a = b;      //
            b = c;      //
            //cout << "fib[" << i-1 <<"] = " << a << endl;
        }
    }
    return b;

}

double fib2(int n){ 
//supports til n = 47
        
    int seq[n] = {0, 1};

    for(int i = 2; i < n; i ++){
        seq[i] = seq[i-1] + seq[i-2];
    }
    return seq[n-1];

}

int main(){

    int num;

    cout << "fib pos: ";
    cin >> num;
    //printf("Fib num: %.lf", fib1(num));
    printf("fib[%d] = %.lf", num, fib1(num));

    cout << endl;
    return 0;
}