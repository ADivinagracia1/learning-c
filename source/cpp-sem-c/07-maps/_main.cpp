#include "_header.h"

//Map - store using key valued pairs (no duplicates)

int main(){

    map<int, string> map1;
    map1.insert(pair<int, string> (1, "Bart"));
    map1.insert(pair<int, string> (2, "Lisa"));
    map1.insert(pair<int, string> (3, "Marge"));
    map1.insert(pair<int, string> (4, "Homer"));

    //Find
    auto match = map1.find(2);
    cout << match->second << endl;

    //Upper and Lower Bounds 
    auto bart = map1.lower_bound(1);
    cout << "LB: " << bart->second << endl; //note: Second = string
    auto lisa = map1.upper_bound(1);        //      First  = int
    cout << "UB: " << lisa->second << endl;

    //Output using iterator
    map<int, string>::iterator it2;
    for(it2 = map1.begin(); it2 != map1.end(); it2++){
        cout << "Key: " << it2-> first << "\tValue: " << it2->second << endl;
    }

    cout << endl;
    return 0;
}
