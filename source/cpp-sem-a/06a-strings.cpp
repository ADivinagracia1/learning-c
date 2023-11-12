#include "header.h"

int main(){

    //stringBasics1();
    stringBasics2();
    //stringOrInt();
    //stringStream();

    std::cout << std::endl;
    return 0;

}

void stringBasics1(){

    string str1 = "I am a string";

    //String Funcitons
    cout << "First:\t" << str1[0] << endl;
    cout << "Last:\t" << str1.back() << endl;
    cout << "Length:\t" << str1.length() << endl;
    cout << "Append:\t" << str1.append("!") << endl;

    //Copy full string
    string str2 = str1;     
    cout << "Copied to str2:\t\t" << str2 << endl;

    //Copy string after first 5 characters
    string str3(str2, 5);   
    cout << "Copied after 5 chars:\t" << str3 << endl;

    //Adding another string
    string str4 = str1 + " and you're not";
    cout << "Add another string:\t" << str4 << endl;
    
}

void stringBasics2(){

    string strA = "I am another string";

    //Deletes strig except for first 10
    strA.erase(10, strA.length() - 1);
    cout << "Keep 1st 10 chars:\t" << strA << endl;

    //Substring                      (index,#of chars)
    cout << "Substring:\t\t" << strA.substr(2,8) << endl;

    //Find String                      npos = end of string
    if(strA.find("am") != string::npos){
        cout << "Index of \"am\" is " << strA.find("am") << endl;
    }

    //Change numbers to String
    string strNum = to_string(4+12);
    cout << "String Number: " << strNum << endl;

}

void stringOrInt(){
    //Doesnt work ???

    char letterZ = 'Z';
    char num5    = '5';
    char aSpace  = ' ';

    cout << "Is letterZ a letter or number? " << isalnum(letterZ) << endl;
    cout << "Is letterZ a letter? "           << isalpha(letterZ) << endl;
    cout << "Is num5 a number? "              << isdigit(num5)    << endl;
    cout << "Is aSpace a space? "             << isspace(aSpace)  << endl;
}

void stringStream(){

    //String Stream*
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