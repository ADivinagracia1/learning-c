#include "_header.h"

static int outCount = 0;

void dequeNotes();
void listOutput(deque<int> deck);

int main(){

    dequeNotes();

    cout << endl;
    return 0;
}

void dequeNotes(){
    deque<int> deq1;

    //Push functions (Out1)
    deq1.push_back(5);      //Assigns 5 at the end
    deq1.push_front(1);     //Assigns 1 at the start
    listOutput(deq1);

    //Assign (Out2)
    deq1.assign({11, 12});  //Overrides 5 and 1
    deq1.push_front(7);     //Adds 7 at the start
    listOutput(deq1);

    //Calling Values at certain indecies (+calling size)
    cout << "Size:\t" << deq1.size() << endl;
    cout << "deq[0]:\t" << deq1[0] << endl;
    cout << "deq[1]:\t" << deq1.at(1) << endl;     

    //Add values at certain indecies (Out3)
    deque<int>::iterator iter = deq1.begin() + 2;   //determines location to store 
    deq1.insert(iter, 79);                          //adds 79 in 3rd position
    listOutput(deq1);
    
    //Insert values in array (Out4)
    int tempArr[5] = {56, 57, 58, 59, 510};
    deq1.insert(deq1.begin()+2, tempArr, tempArr+5);    //Inserts tempArr values starting 3rd position (___+2)
    listOutput(deq1); 

    //Erase Function (Out5)
    deq1.erase(deq1.end());                         //Erase last number (12)
    deq1.erase(deq1.begin()+1, deq1.begin()+3);     //Erase 2nd and 3rd numbers (11 and 56)
    listOutput(deq1);

    //Pop functions (Out6)
    deq1.pop_back();    // Deletes 9
    deq1.pop_front();   // Deletes 79
    listOutput(deq1);

    //Swap (Out7)
    deque<int> deq2(2, 6);     //deq2 will not be called, but the contents will remain 
    deq1.swap(deq2);            //Swap contents
    listOutput(deq1);

    //Clear (Out8)
    deq1.clear();
    listOutput(deq1);

}

void listOutput(deque<int> deck){
    outCount++;
    cout << "Out" << outCount << ":\t";
    for(int i: deck){
        cout << i << " ";
    }
    cout << endl;
}