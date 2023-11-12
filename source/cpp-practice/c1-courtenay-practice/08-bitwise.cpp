#include <iostream>
#include <bitset>
using namespace std;

bitset<8> bitwiseNOT(int n){  
    bitset<8> x(~n);
    return x;   }

bitset<8> bitwiseAND(int n, int m){
    bitset<8> x(n & m);
    return x;   }

bitset<8> bitwiseOR(int n, int m){
    bitset<8> x(n & m);
    return x;   }

bitset<8> bitwiseXOR(int n, int m){
    bitset<8> x(n ^ m);
    return x;   }

bitset<8> bitwiseRSHIFT(int n){ 
    bitset<8> x(n >> 1);
    return x;   }

bitset<8> bitwiseLSHIFT(int n){
    bitset<8> x(n << 1);
    return x;   }

int main(){

    int a = 256, b = 9;    
    bitset<8> h(a), k(b);
    cout << a << ":\t" << h << endl;
    cout << b << ":\t" << k << endl;
    cout << "~" << b << ":\t"      << bitwiseNOT(b) << endl;
    cout << a << "&" << b << ":\t" << bitwiseAND(a, b) << endl;
    cout << a << "|" << b << ":\t" << bitwiseOR(a, b) << endl;
    cout << a << "^" << b << ":\t" << bitwiseXOR(a, b) << endl;
    cout << a << ">>1:\t"          << bitwiseRSHIFT(a) << endl;
    cout << a << "<<1:\t"          << bitwiseLSHIFT(a) << endl;
    
    //255 = 1111 1111
    //256 = 0000 0000
    cout << "\t8  5   1" << endl;

    cout << endl;
    return 0;
}