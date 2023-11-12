#include "_header.h"

//Queue - can only alter the first and last values FIFO

void QueueBasics();
void PrioQueue();

int main(){

    //QueueBasics();
    PrioQueue();

    cout << endl;
    return 0;
}

void QueueBasics(){

    queue<string> boys;
    boys.push("Hughie");
    boys.push("Butcher");
    boys.push("Frenchie");
    boys.push("MM");
    boys.push("Kimiko");

    cout << "Size: " << boys.size() << endl;
    while(!boys.empty()){
        cout << boys.front() << endl;
        boys.pop();
    }

}


void PrioQueue(){

    priority_queue<int> nums;
    nums.push(4);
    nums.push(8);
    nums.push(5);
    nums.push(12);

    cout << "Size: " << nums.size() << endl;
    while(!nums.empty()){
        cout << nums.top() << endl;         //outputs in sorted order
        nums.pop();
    }

}