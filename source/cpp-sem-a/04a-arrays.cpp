#include "header.h"

int main(){

    //arrayBasics();
    vectorBasics();

    std::cout << std::endl;
    return 0;

}

int arrayBasics(){
    //Arrays - Storage of values

    //Declaring Array
    int arrnNums1[10] = {1};
    int arrnNums2[]   = {1, 2 ,3};
    int arrnNums3[5]  = {8, 9};

    cout << "1st Value: " << arrnNums3[0] << endl;
    arrnNums3[0] = 7;    
    cout << "1st Value: " << arrnNums3[0] << endl;

    //3D Array
    int arrnNums4[2][2][2] = {  {   {1, 2}, {3, 4}  }, 
                                {   {5, 6}, {7, 8}  }    };
    cout << arrnNums4[0][1][1] << endl;
    
}

int vectorBasics(){
    //Vectors - used when size of the array is unknown

    vector<int> vNums(3);

    vNums[0] = 1;
    vNums[1] = 2;
    cout << "Vector Size: " << vNums.size() << endl;
    vNums.push_back(3);
    cout << "Vector Size: " << vNums.size() << endl;

    for(int i = 0; i < vNums.size(); i++){
        cout << vNums[i] << endl;
    }
    
    /*
    cout << vNums[0] << endl;
    cout << vNums[1] << endl;
    cout << vNums[2] << endl;
    cout << vNums[3] << endl;
    */

}