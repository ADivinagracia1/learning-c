#include "_header.h"

//Like a list, but each node only looks forward
//no way to obtain values backwards (sequence containers)

static int outCount = 0;
void OutputList(forward_list<int> liOut);

int main(){

    forward_list<int> fl1;
    fl1.assign({1,2,3,4});
    OutputList(fl1);

    fl1.push_front(0);
    OutputList(fl1);

    fl1.pop_front();
    OutputList(fl1);

    cout << "Front Value: " << fl1.front() << endl;

    forward_list<int>::iterator it1 = fl1.begin();
    it1 = fl1.insert_after(it1, 7);     //insert after first value
    OutputList(fl1);

    fl1.emplace_front(6);   //places 6 at front (like push?)
    OutputList(fl1);

    fl1.remove(3);          //removes the value 3
    OutputList(fl1);    

    //remove_if calls a function, or a struct

    forward_list<int> fl2;
    fl2.assign({9, 9, 9, 8});
    fl1.merge(fl2);
    OutputList(fl1);

    cout << endl;
    return 0;
}

void OutputList(forward_list<int> liOut){
    outCount++;
    cout << "Out" << outCount << ": ";
    for(int i: liOut){
        cout << i << " ";
    }
    cout << endl;
}
