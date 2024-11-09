// https://www.w3resource.com/c-programming-exercises/pointer/index.php

#include <stdio.h>

int main(int argv, char** argc)
{
    int m, n, o;
    int* z;

    m = 10;
    z = &m;
    // *z = m; UNECESARY

    printf("%d\n",m);
    printf("%p\n",z);
    printf("%d\n",*z);
    printf("%p\n",&m);
    printf("%p\n",&n);
    printf("%p\n",&o);

    return 0;
}