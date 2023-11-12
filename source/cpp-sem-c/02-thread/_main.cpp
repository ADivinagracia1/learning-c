#include "_header.h"

//Thread - block of code that executes at the same time in a certain condition
//         ex. when one thread is put to sleep
// VS CODE DOES NOT LIKE OUTPUTTING THREADS

int GetRandom(int max){
    srand(time(NULL));
    return rand() & max;
}


void ExecuteThread(int id){
    auto nowTime = chrono::system_clock::now();
    time_t sleepTime = chrono::system_clock::to_time_t(nowTime);
    tm myLocalTime = *localtime(&sleepTime);

    cout << "Thread: " << id << endl;
    cout << "Sleep Time: " << ctime(&sleepTime) << endl;

    cout << "Day:\t" << myLocalTime.tm_mday << endl;  //day   = tm_mday
    cout << "Day:\t" << myLocalTime.tm_mday << endl;  //day   = tm_mday
    cout << "Year:\t" << myLocalTime.tm_year << endl; //year  = tm_year
    cout << "Hour:\t" << myLocalTime.tm_hour << endl; //hour  = tm_hour
    cout << "Secs:\t" << myLocalTime.tm_sec << endl;  //secs  = tm_sec

    //-----------------------------------------------------------------------

    this_thread::sleep_for (chrono::seconds(GetRandom(3)));
    nowTime = chrono::system_clock::now();
    sleepTime = chrono::system_clock::to_time_t(nowTime);

    cout << "Thread: " << id << endl;
    cout << "Awake Time: " << ctime(&sleepTime) << endl;

}


int main(){
//note: Main is a thread

    thread th1 (ExecuteThread, 1);
    th1.join(); //waits for th1 before executing

    cout << endl;
    return 0;
}
