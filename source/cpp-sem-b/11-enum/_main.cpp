#include "_header.h"

int main(){

    enum day {Mon, Tues = 2, Wed, Thur, Fri};       //assigns 0, 2, 3, 4, 5
    enum day checkMON = Mon;
    enum day checkWED = Wed;
    cout << "Monday = " << checkMON << endl;        //return 0
    cout << "Wednesday = " << checkWED << endl;     //return 3

    //Monday = 0,       Friday = 5
    for (int i = Mon; i <= Fri; i++){
        cout << i << endl;
    }

    cout << endl;
    return 0;
}
