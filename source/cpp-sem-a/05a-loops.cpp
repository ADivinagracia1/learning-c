#include "header.h"

int main(){

    //whileBasics();
    //whileForSS();
    doWhile();

    std::cout << std::endl;
    return 0;

}


int whileBasics(){
    //Used when looping variable is outside the loop

    int i = 1;
    while( i <= 20){

        //Skips even numbers
        if( i % 2 == 0) {       
            i++;
            continue; //acts after the condition
        }

        //stops/resets the loop when i == 15
        if(i == 15) break;

        cout << i << endl;
        i++;
    }

}

int whileForSS(){

    //String Stream
    vector<string> words;
    stringstream ss("Some Random Words Seperated By Space");
    string one_word;

    while(getline(ss, one_word, ' ')){
        words.push_back(one_word);
    }

    //For Loop
    for(int i = 0; i < words.size(); i++){
        cout << words[i] << endl;
    }

    //Shortened for loop (works for arrays)
    for(auto x: words) cout << "(shorten) " << x  << endl;
    
}

int doWhile(){

    srand(time(NULL));
    int secretNum = rand() % 11; //values are from 0 to 10
    int guess;

    do{
        cout << "Guess the Number: ";
        cin >> guess;
        if(guess > secretNum) cout << "Too Big" << endl;
        if(guess < secretNum) cout << "Too Small" << endl;

    }while(secretNum != guess);

    cout << "You guessed it!" << endl;

}