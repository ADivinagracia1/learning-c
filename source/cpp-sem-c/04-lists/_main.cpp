#include "_header.h"

//List - used for insertion and deletion
static int outCount = 0;

void OutputList(list<int> liOut);
void ListBasics();
void ListExclFunc();

int main(){

    //ListBasics();
    ListExclFunc();

    cout << endl;
    return 0;
}

void ListExclFunc(){
    
    //Sort (compare with assign)
    int arr2[6] = {10,12, 8, 7, 6, 6};
    list<int> list2;
    list2.insert(list2.begin(), arr2, arr2+6);
    OutputList(list2);

    list2.sort();
    OutputList(list2);

    list2.reverse();
    OutputList(list2);
    
    list2.unique();
    OutputList(list2);

    list2.remove(6);
    OutputList(list2);
    
    //list2.remove_if(); requires a struct
    //OutputList(list2);

    //can use merge funciton 

}

void ListBasics(){

    int arr[5] = {1, 2, 3, 4, 5};
    list<int> list1;

    //inserts arr values (Out1)
    list1.insert(list1.begin(), arr, arr+5);
    OutputList(list1);      

    //assign overrides values before (Out2)
    list1.assign({11, 12});
    OutputList(list1);      

    //push (Out3)
    list1.push_back(5);
    list1.push_back(9);
    list1.push_front(7);
    OutputList(list1);

    cout << "\tSize: " << list1.size() << endl;
    //cout << list1[0] << endl;     //will cause an error

    //note: iterators loop through the container
    list<int>::iterator it2 = list1.begin();
    advance(it2, 1);                //needs an iterator
    cout  << "\tlist1[1]: " << *it2 << endl;

    //Insert 8 at beginning (Out4)
    list1.insert(list1.begin(), 8);
    OutputList(list1);

    //Erase 8 at beginning (Out5)
    list1.erase(list1.begin());
    OutputList(list1);

    //Erase with iterators (Out6)
    list<int>::iterator it3 = list1.begin();
    advance(it3, 3);            //it2 delets 11
    list1.erase(it2, it3);      //it3 delets 12
    OutputList(list1);

    //Pop (Out7)
    list1.pop_front();      //deletes 7
    list1.pop_back();       //deletes 9
    OutputList(list1);

}

void OutputList(list<int> liOut){
    outCount++;
    cout << "Out" << outCount << ": ";
    for(int i: liOut){
        cout << i << " ";
    }
    cout << endl;
}