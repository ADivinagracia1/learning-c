#include <string>
#include <iostream>
using namespace std;

void integerNotes();
void charNotes();

int main(){
    cout << "yoyet" << endl;
    charNotes();
    return 0;
}

void integerNotes(){
    //int
    int myVariableName7;            // stores from -32768 to +32767
    signed int myVariableName8;     // stores from -32768 to +32767
    unsigned int myVariableName9;   // stores from 0 to +65535

    //short == 16bit
    short myVariableName1;              //bytes and  stores from -32768 to +32767
    short int myVariableName2;          //stores from -32768 to +32767
    signed short myVariableName3;       // stores from -32768 to +32767
    signed short int myVariableName4;   // stores from -32768 to +32767
    unsigned short myVariableName5;     // stores from 0 to +65535
    unsigned short int myVariableName6; // stores from 0 to +65535

    //long =- 32 bit
    long myVariableName10;              // stores from -2147483648 to +2147483647
    long int myVariableName11;          // stores from -2147483648 to +2147483647
    signed long myVariableName12;       // stores from -2147483648 to +2147483647
    signed long int myVariableName13;   // stores from -2147483648 to +2147483647
    unsigned long myVariableName14;     // stores from 0 to +4294967295
    unsigned long int myVariableName15; // stores from 0 to +4294967295
}

void charNotes(){
    char myChar='A';
    char myOtherChar=65;
    cout << "Value of myChar is: "<< myChar<<endl;
    cout << "Value of myOtherChar is: "<< myOtherChar<<endl;
}