#include <iostream>
#include <vector>
using namespace std;

int main(){

    //int arr[] = {354, 900, 280, 1000, 533, 751};
    int arr[] = {354, 900, 280, 1000, 533, 751, 489, 1999, 89, 500, 666, 250, 1371, 1600, 890, 101, 34, 696, 201, 1891, 1206, 705, 608, 511, 1114, 875, 1994, 5, 948, 1500};
    int arrSize = *(&arr + 1) - arr;
    int i, j, item;

    //Side note:
    //cout << (&arr + 1) << endl;  //0x7ffffffede78, end of array
    //cout << *(&arr + 1) << endl; //0x7ffffffede78, needed for int opetaion
    //cout << arr << endl;         //0x7ffffffede00, start of array

    for(i = 0; i < arrSize; i++){
        
        item = arr[i];
        j = i - 1;              //care about one above the current size

        while( j>=0 && arr[j] > item){
            arr[j+1] = arr[j];  //shifting down
            j--;
        }
        arr[j+1] = item;        //assign it!

    }

    for(int i = 0; i < arrSize; i++)
        cout << i+1 << ". " << arr[i] << endl;
    
    cout << endl;
    return 0;
}