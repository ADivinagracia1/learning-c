#include "_header.h"

void iteratOut();
void iteratAdv();
void iteratNextPrev();
void iteratCopy();

int main(){

    //iteratOut();
    //iteratAdv();
    //iteratNextPrev();
    iteratCopy();

    cout << endl;
    return 0;
}

void iteratOut(){

    vector<int> nums = {1, 2, 3, 4};
    vector<int>::iterator itr;
    
    for (itr = nums.begin(); itr < nums.end(); itr++){
        cout << *itr << ", ";
    }

}

void iteratAdv(){

    vector<int> nums = {1, 2, 3, 4};
    vector<int>::iterator itr;

    vector<int>::iterator itr2 = nums.begin();
    advance(itr2, 2);
    cout << "Advance: " << *itr2 << endl;

}

void iteratNextPrev(){

    vector<int> nums = {6, 5, 213, 4};
    vector<int>::iterator itr = nums.end();

    cout << "Now:  " << *itr << endl;

    auto itr2 = next(itr, 1);
    cout << "Next: " << *itr2 << endl;
    auto itr3 = prev(itr, 1);
    cout << "Prev: " <<  *itr3 << endl;

}

void iteratCopy(){
    
    vector<int> nums1 = {1, 4, 5, 6};    
    vector<int> nums2 = {22, 77, 33};
    auto itr = nums1.begin();

    advance(itr, 2); //determines where to start placing
    copy(nums2.begin(), nums2.end(), inserter(nums1, itr)); //insert nums2 values at nums1

    for(int &i: nums1){
        cout << i << ", ";
    }

}
