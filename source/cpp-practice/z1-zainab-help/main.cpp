#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){

    vector<string> phraseVector;
    string userPhrase;
    int charCount = 9999;
    cout << "Please enter a phrase" << endl;

    while( charCount > 0){

        cin >> userPhrase;
        phraseVector.push_back( userPhrase );
       
       charCount = 0;
        for(int i = 0; i < userPhrase.size(); i++ )
            cout << charCount++ << endl;

    }

    for( int i = 0; i < phraseVector.size(); i++)
        cout << phraseVector[i] << endl;

    return 0;

}