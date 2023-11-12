#include "_header.h"

void mAllocEx(int numOfVals);
void smrtPointer(int numOfVals);

//MALLOC = MEMORY ALLOCATION (also pointers)
int main(){

    int toStore;
    cout << "How many numbers do you want to store? ";
    cin >> toStore;

    mAllocEx(toStore);
    //smrtPointer(toStore);

    cout << endl;
    return 0;
}

void mAllocEx(int numOfVals){

    //Create space in a variable pNums (NOT ARRAY)
    // --> uses enough space only for how much values there are 
    int *pNums;
    pNums = (int *) malloc(numOfVals * sizeof(int));

    //pNums points to array
    if(pNums != NULL){
        int i = 0;
        while(i < numOfVals){
            cout << "Enter a Number: ";
            cin >> pNums[i];
            i++;
        }
    }

    cout << "You entered these numbers" << endl;
    for(int i = 0; i < numOfVals; i++){
        cout << pNums[i] << ", ";
    }
    delete pNums;

}

void smrtPointer(int numOfVals){

    //automattically reallocated memory
    unique_ptr<int[]> pNums( new int[numOfVals]);

    if(pNums != NULL){
        int i = 0;
        while(i < numOfVals){
            cout << "Enter a Number: ";
            cin >> pNums[i];
            i++;
        }
    }

    cout << "You entered these numbers" << endl;
    for(int i = 0; i < numOfVals; i++){
        cout << pNums[i] << ", ";
    }

}
