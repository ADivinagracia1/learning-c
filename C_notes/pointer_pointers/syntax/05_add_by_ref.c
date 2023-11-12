#include <stdio.h>

int addByReference(int* a, int* b);

int main(int argc, char** argv)
{
    int num1 = 5, num2 = 6;

    printf("(before) a = %d\n", num1);
    int c = addByReference(&num1, &num2);
    printf("(after)  a = %d\n", num1);

    printf("%d + %d = %d\n", num1, num2, c);

    return 0;
}

int addByReference(int* a, int* b)
{
    *a = 2;
    return (*a) + (*b);
}