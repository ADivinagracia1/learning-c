#include "IVector.h"
#include "List.h"
#include <iostream>
#include <time.h> 
using namespace std;

double elapsed_time( clock_t start, clock_t finish){
   // returns elapsed time in milliseconds
   return (finish - start)/(double)(CLOCKS_PER_SEC/1000);
}

int main (int argc, char * const argv[]) {

    clock_t start, insertVec, insertList, finishVec, finishList;
    int size = 10000000;



    start = clock(); //----------------------------------------
    IVector myVector;
    for (int i = 0; i < size; i++){    
        myVector.push_back(i);
    }
    insertVec = clock(); //------------------------------------

    List<int> myList;
    for (int i = 0; i < size; i++){    
       myList.push_back(i);
    }
    insertList = clock(); //-----------------------------------

    myVector.visitAll();

    finishVec = clock(); //------------------------------------

    myList.visitAll();

    finishList = clock(); //-----------------------------------

    cout << "Andrei Divinagracia" << endl;
    cout << "301360608" << endl;
    cout << "adivinag" << endl;
    cout << "Program: " << "part1.cpp" << endl;
    cout << "Type of Element: " << "int" << endl;
    cout << "Number of Elements: " << size << endl;
    cout << "Time Units: " << "milliseconds" << endl;
    cout << "Time for Vector Insertion: " << elapsed_time(start,insertVec) << endl;
    cout << "Time for List Insertion: " << elapsed_time(insertVec,insertList) << endl;
    cout << "Time for Vector Visiting: " << elapsed_time(insertList,finishVec) << endl;
    cout << "Time for List Visiting: " << elapsed_time(finishVec,finishList) << endl;
}   