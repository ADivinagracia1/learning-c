#include <stdio.h>

int getFactorial(int inp);

int main(){

    int num = 5;
    printf("%d! = %d", num, getFactorial(num));

    return 0;
}

int getFactorial(int inp){

    if ( inp <= 1 )
        return 1;
        
    return inp*getFactorial(inp - 1);
}