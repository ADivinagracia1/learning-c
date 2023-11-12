#include "header.h"

int main(){

    //printfNotes()
    basicMath();
    
    std::cout << std::endl;
    return 0;

}


void printfNotes(){

    printf("%c|%d|%5d|%.3f|%s\n",
            'A', 10, 5, 3.1415, "I'm a String");
    // %c    print assigned Character
    // %d    print integer
    // %5d   print 5 spaces then integer
    // %.3f  print only 3 decimal places
    // %s    print full string
    // \n    equivalent to endl

}

void basicMath(){

    std::string num1, num2;
    std::cout << "Enter a Number: ";
    std::cin >> num1;
    std::cout << "Enter another Number: ";
    std::cin >> num2;

    //convert variable type s-to-i [casting]
    int nNum1 = stoi(num1);
    int nNum2 = stoi(num2);

    printf("%d + %d = %d\n", nNum1, nNum2, nNum1 + nNum2);
    printf("%d - %d = %d\n", nNum1, nNum2, nNum1 - nNum2);
    printf("%d * %d = %d\n", nNum1, nNum2, nNum1 * nNum2);
    printf("%d / %d = %d\n", nNum1, nNum2, nNum1 / nNum2);
    printf("%d %% %d = %d\n", nNum1, nNum2, nNum1 % nNum2);

}
