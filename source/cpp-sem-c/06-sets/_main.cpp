#include "_header.h"

//Sets - Store UNIQUE sorted values using a key
//Multisets - Similar to set, but duplicate values are sorted in order
static int outCount = 0;
void OutputSet(set<int> setOut);

void setBasics();
void setExclusive();
void multiSet();

int main(){

    setBasics();
    //setExclusive();
    //multiSet();

    cout << endl;
    return 0;
}

void setBasics(){
    
    //Assign and insert (Out1)
    set<int> set1 {5,4,3,2,1,1,2};
    cout << "Size: " << set1.size() << endl;
    set1.insert(0);
    OutputSet(set1);

    //Cannot access values, need iterator
    set<int>::iterator it1 = set1.begin();
    it1++;              //cycles iterator once
    cout << "2nd: " << *it1 << endl;    
    advance(it1, 2);    //cycles iterator twice
    cout << "4th: " << *it1 << endl;

    //Erase (Out2)
    set1.erase(4);
    OutputSet(set1);    //deletes 4 in the list

    //Erase with iterators (Out3)
    it1 = set1.end();
    advance(it1, -2);
    set1.erase(it1, set1.end()); //delets last 2 elements
    OutputSet(set1);

    //Insert Array (Out4)
    int arr[] = {6,7 ,8 ,9};
    set1.insert(arr, arr+4);
    OutputSet(set1); 

}

void setExclusive(){
    
    set<int> set1 {5,4,3,2,1,1,2};

    //Find value in set based off out4 (not position)
    auto val = set1.find(8);
    cout << "Find: " << *val << endl;

    //Upper/Lower Bound
    auto eight = set1.lower_bound(8);
    cout << "eight: " << *eight << endl;
    auto nine = set1.upper_bound(9);
    cout << "nine:  " << *nine << endl;

    //Swap (Out5)
    set<int> set2 {332, 5432};
    set1.swap(set2);
    OutputSet(set1);    

}

void multiSet(){
    multiset<int> mset1 {1, 1, 1, 2, 3, 3, 4};
    mset1.insert(7);
    mset1.insert(-1);

    if(!mset1.empty()){
        for(int i: mset1){
        cout << i << " ";
        }
    }
}

void OutputSet(set<int> setOut){
    outCount++;
    cout << "Out" << outCount << ": ";
    for(int i: setOut){
        cout << i << " ";
    }
    cout << endl;
}

