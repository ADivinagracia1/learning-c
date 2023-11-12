#include "header.h"

int main(){

    //ifStatement()
    shortIfStatement();

    std::cout << std::endl;
    return 0;

}

void ifStatement(){

    // Conditional Operators:   >, <, >=, <=, ==, !=
    // Logical Operators:       &&, ||, !

    string sAge;
    cout << "Enter Your Age: ";
    cin >> sAge;
    int nAge = stoi(sAge);

    if((nAge >= 1) && (nAge <= 18))   {    cout << "Important Birthday" << endl;    }
    else if( nAge == 21 || nAge == 50){    cout << "Important Birthday" << endl;    }
    else if( nAge >= 65)              {    cout << "Important Birthday" << endl;    }
    else                              {    cout << "Not an Important Birthday" << endl;    }

}


void shortIfStatement(){
    
     //equivalent to if statement, with assigning value
    int age43 = 43;
    bool canIVote = (age43 >= 18) ? true : false;
                // Condition        if      else

    //Converts 1,0 to true, false
    cout.setf(ios::boolalpha);
    cout << "Can Derek Vote?: " << canIVote << endl;

}