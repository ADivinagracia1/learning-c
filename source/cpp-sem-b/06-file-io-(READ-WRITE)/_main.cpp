#include "_header.h"

//ios_base::app   - append
//ios_base::trunc - delete file if already exists
//ios_base::in    - open for reading
//ios_base::out   - open file for writing 
//ios_base::ate   - open and add stuff file at end

int main(){

    ofstream writeToFile;
    ifstream readFromFile;
    string txtWrite = "";
    string txtRead = "";

    /*
    writeToFile.open("test.txt", ios_base::out | ios_base::trunc);
    if(writeToFile.is_open()){
        writeToFile << "Beginning of File\n";
        cout << "Enter data to write: ";
        getline(cin, txtWrite);
        writeToFile << txtWrite;
        writeToFile.close();
    }*/
    

   
   readFromFile.open("test.txt", ios_base::in);
   if(readFromFile.is_open()){

       while(readFromFile.good()){
           getline(readFromFile, txtRead);
           cout << txtRead << endl;
       }
       readFromFile.close();
   }


    cout << endl;
    return 0;
}
