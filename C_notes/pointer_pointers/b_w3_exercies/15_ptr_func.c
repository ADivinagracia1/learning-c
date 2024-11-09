#include <stdio.h>

// expects an integer address as the return value
int * findLarer(int *a, int *b)
{
    if (*a > *b)    // compare values
        return a;   // returns address
    else
        return b;   // returns address
}

int main(int argc, char const *argv[])
{
    int num1, num2, *result;
    printf("input 2 numbers: ");
    scanf("%d", &num1);
    scanf("%d", &num2);

    result = findLarer(&num1, &num2);

    printf("%d is bigger", *result);

    return 0;
}
