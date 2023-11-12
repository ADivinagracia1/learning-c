struct node{
    int data;
    node *next;
};

class LL{
private:
    node *head, *tail;
public:
    LL();
    LL(double n);
    ~LL();
    void push(double n);
    double pop();
    bool empty();
};

bool LL::empty(){
    return head == nullptr;
}

LL::LL(){
    head = nullptr;
    tail = nullptr;
}


/*
struct Node{
    double data;
    double *dataPtr;    
};

class LL{
private:
    double *first = nullptr;

public:
    LL();
    LL(double n);
    ~LL();
    void push(double n);
    double pop();
    bool empty();
};

LL::LL(){   }
LL::LL(double n){   }
LL::~LL() = default;

bool LL::empty(){
    return this->first == nullptr;
}

void LL::push(double n){
    if(empty()){
        Node new;
        new.data = n;
        new.dataPtr = nullptr;
        this->first = new;
    }
    else{
        
    }
}

double LL::pop(){
    
}
*/
