// #include <iostream>
// using namespace std;

// int adr;

// void x(int * inp){
//     *inp = (*inp)*2;
//     cout << "In x()\t" << &inp <<  "\t" << *inp << endl;
// }

// void a(int *q){
//     *q = 7;
//     cout << "In a()\t" << &q <<  "\t" << *q << endl;
//     x(q);
// }

// int main(){
//     int *b;
//     cout << "main()\t" << &b <<  "\t" << *b << endl;
//     a(b);
//     cout << "main()\t" << &b <<  "\t" << *b << endl;

//     cout << endl;

//     // int i = 2 ;
//     // int * pi = &i ;
//     // int a[3] = {9,8,7} ;
//     // cout << i+a[1] << ";" << *pi << ";" << a << endl ;

// }

#include <iostream>
using namespace std;

class Store{
  public:
    Store(int C){
       X = C ;
       b = new int[1] ;
       b[0] = C+1 ;
    }
    int X ;
    int * b ;
};

int main(){
  
  cout << "Hello World" << endl;
  /*
  int Y ;
  int *Z = new int ;
  Y = 1 ;
  *Z = 2 ; 
  int a[2] = {3,4} ;
  int *b = new int[1] ;
  b[0] = 9 ; 
  Store W(5) ;
  Store * V = new Store(7);
  */
}