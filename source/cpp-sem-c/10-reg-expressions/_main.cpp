#include "_header.h"

//Regular Expression - way of defining informaiton we want to search for (str, int...)

int main(){

    string str = "The ape was at the apex";
    regex reg("(ape)[^ ]?"); //looks for "ape" with a space AND without a space 

    smatch matches;

    if(regex_search(str, matches, reg) == true){
        cout << matches.size() << " Matches" <<endl;

        while(regex_search(str, matches, reg)){
            cout << matches.str(1);                     //Get the first match
            cout << ", Starting at index " << matches.position(1) << endl; 

            //Eliminate current string and proceed to next match
            str = matches.suffix().str();

        }

    }

    cout << "Check" <<endl;
    return 0;
}
