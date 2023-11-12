#include "header.h"

using namespace std;

//Global Variables, Usable on every function
int imGlobal = 0;
const int PI = 3.1415;

int main(int argc, char** argv){

    cout << "Variables!" << endl;

    //declNotes();
    //accuNotes();
    charNotes();
    //intNotes();

    cout << endl;
    return 0;

}

void declNotes(){
    //Declaration
    bool married = true;
    char myGrade = 'A';
    auto whatAmI = 6;
}

void accuNotes(){
    //Float Accuracy
    float f1 = 1.1111111;
    float f2 = 1.1111111;
    printf("Sum = %.7f\n", (f1 + f2)); //outputs 2.2222221, wont go to 7 decimal places

    //Double accuracy 
    float d1 = 1.1111111111111111;
    float d2 = 1.1111111111111111;
    printf("Sum = %.7f\n", (d1 + d2)); //outputs 2.2222221, wont go to 16 decimal places

}

void charNotes(){
    char myChar='A';
    char myOtherChar=65;
    cout << "Value of myChar is: \t "<< myChar<<endl;
    cout << "Value of myOtherChar is: "<< myOtherChar<< " [But written in a number ;)] " << endl;
}

void intNotes(){
    //Min/Max of data types
    cout << "Min and Max Values--------------------------------" << endl;
    cout << "Min short uint: " << numeric_limits<unsigned short int>::min() << endl;
    cout << "Max short uint: " << numeric_limits<unsigned short int>::max() << endl;
    cout << "Min short int: \t" << numeric_limits<short int>::min() << endl;
    cout << "Max short int: \t" << numeric_limits<short int>::max() << endl;
    cout << "Min int: \t" << numeric_limits<int>::min() << endl;
    cout << "Max int: \t" << numeric_limits<int>::max() << endl;
    cout << "Min float: \t" << numeric_limits<float>::min() << endl;
    cout << "Max float: \t" << numeric_limits<float>::max() << endl;
    cout << "Min double: \t" << numeric_limits<double>::min() << endl;
    cout << "Max double: \t" << numeric_limits<double>::max() << endl;
    cout << "Min long double: " << numeric_limits<long double>::min() << endl;
    cout << "Max long double: " << numeric_limits<long double>::max() << endl;
}