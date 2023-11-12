#include "_header.h"

//Not Lambda, using function to create a random vector
vector<int> GenerateRandVect(int numOfNums, int min, int max);

vector<int> lambdaSortCompare(vector<int> listVect);
vector<int> lambdaSortEven(vector<int> listVect);
void lambdaSum(vector<int> listVect);

int main(){

    vector<int> varList = GenerateRandVect(10, 1, 50);
    vector<int> result;

    for(auto val: varList){
        cout << val << ", "; 
    }
    cout << endl;  

    //result = lambdaSortCompare(varList);
    //result = lambdaSortEven(varList);
    lambdaSum(varList);

    for(auto res: result){
        cout << res << ", "; 
    }

    cout << endl;
    return 0;
}

vector<int> lambdaSortCompare(vector<int> listVect){     
    sort(listVect.begin(), listVect.end(), [](int x, int y){ return x < y; });
                                              //Lambda expressions - list operations - []
    return listVect;
}
vector<int> lambdaSortEven(vector<int> listVect){
    vector<int> evenlistVec;             //Take suvessful values into evenlistVec
    copy_if(listVect.begin(), listVect.end(), back_inserter(evenlistVec), [](int x){ return  (x%2) == 0; } );
                                                                //Condition to place values into evenlistVec
    return evenlistVec;
}
void lambdaSum(vector<int> listVect){
    int sum = 0;                             // & allows for external values
    for_each(listVect.begin(), listVect.end(), [&](int x){ return sum = sum + x; } );
    cout << "The sum is " << sum << endl;               
}

vector<int> GenerateRandVect(int numOfNums, int min, int max){
    vector<int> vecValues;
    srand(time(NULL));
    int i = 0;
    int randVal = 0;
    while(i < numOfNums){
        randVal = min + rand() % ((max +1) - min);
        vecValues.push_back(randVal);
        i++;
    }
    return vecValues;
}