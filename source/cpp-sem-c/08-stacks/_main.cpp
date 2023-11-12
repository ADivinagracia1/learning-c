#include "_header.h"

//Stack - Can only modify the first value of the list LIFO

void StackOutput(stack<string> st);

int main(){

    stack<string> boys;
    boys.push("Hughie");
    boys.push("Butcher");
    boys.push("Frenchie");
    boys.push("MM");
    boys.push("Kimiko");

    cout << "Size: " << boys.size() << endl;
    StackOutput(boys);

    return 0;
}

void StackOutput(stack<string> st){
    
    while(!st.empty()){
        cout << st.top() << endl;
        st.pop();
    }
}

/* //Recursive Output that outputs in order of assign
void StackOutput(stack<string> st){

    if(st.empty())
        return;
    
    string x = st.top();
    st.pop();
    StackOutput(st);        //recursive
    cout << x << endl;
    st.push(x);
}*/



