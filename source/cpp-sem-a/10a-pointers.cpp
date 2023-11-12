#include "header.h"

void noPointAssign(int val);
void pointerAssign(int *pVal);
void doubleValues(int *arr, int size);

int main(){

    //pointerBasics();
    pointerTest();
    //pointerArray();

    cout << endl;
    return 0;
}

void pointerBasics(){

    int  age  = 35;
    int *pAge = NULL;
    pAge = &age;
    cout << "Address: " << pAge << endl;
    cout << "Value:\t " << *pAge << endl;

}

void pointerTest(){

    int val43 = 43;

    noPointAssign(val43);
    cout << "val43 = " << val43 << endl;    //outputs 43
    pointerAssign(&val43);
    cout << "val43 = " << val43 << endl;    //outputs 27

}
void noPointAssign(int val){    
    val = 27;   
}
void pointerAssign(int *pVal){  
    *pVal = 27; 
}


void pointerArray(){

    int intArr[] = {1, 253, 8};
    int *pArr = intArr;

    cout << "0th Adr: " << pArr << endl; pArr++;
    cout << "1th Adr: " << pArr << endl; pArr++;
    cout << "2th Adr: " << pArr << endl;

    doubleValues(intArr, 3);
    cout << "0th DubVal: " << intArr[0] << endl;
    cout << "1th DubVal: " << intArr[1] << endl;
    cout << "2th DubVal: " << intArr[2] << endl;
}

void doubleValues(int *arr, int size){
    for(int i = 0; i < size; i++){
        arr[i] = 2*arr[i];
    }
}