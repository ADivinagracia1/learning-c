#include <stdio.h>

void myFactorial(int num, int *res)
{
    *res = 1;
    for ( int i = 0; i < num; i++ ){
        *res *= (num-i);
    }

}

int main(int argc, char** argv)
{
    int num, fact;
    printf("input a number: ");
    scanf("%d", &num);
    myFactorial( num, &fact );
    printf("%d! = %d\n", num, fact);
    return 0;
}