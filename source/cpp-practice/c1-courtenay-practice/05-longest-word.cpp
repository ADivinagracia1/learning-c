#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){

    vector<string> wordList;
    string inp, most;
    int a, max = 0;

    cout << "Type as many words as you want, enter a \';\' when you're done" << endl;

    while(inp.find(";")){
    
        cout << "Type a word: ";
        cin >> inp;
        wordList.push_back(inp);

    }
    wordList.pop_back();

    for(int i=0; i < wordList.size(); i++){

        a = wordList[i].size();
        if(a > max){
            max = a;
            most = wordList[i];
        }
        
    }

    cout << "The first largest word is " << most << " and has " << max << " letters!" << endl;

    cout << endl;
    return 0;
}