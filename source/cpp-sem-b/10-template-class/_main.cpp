#include "_header.h"


//Template Classes - can work with multiple data types

template <typename poo, typename pee, typename cum>
class Person{
public:
    poo height;
    pee weight;
    cum name;
    static int numOfPeople;

    Person(poo h, pee w, cum n){
        height = h;
        weight = w;
        name = n;
        numOfPeople++;
    }

    void GetData(){
        cout << "Height: " << height << endl;
        cout << "Weight: " << weight << endl;
        cout << "Name: " << name << endl;
    }
};

template <typename poo, typename pee, typename cum> int Person<poo,pee,cum>::numOfPeople;

int main(){

    Person<double, int, string> mikeTyson(5.83, 216, "Tyson");
    mikeTyson.GetData();
    cout << "Num of People: " << mikeTyson.numOfPeople << endl;


    cout << endl;
    return 0;
}
