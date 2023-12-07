#include <stdio.h>

int main(int argc, char** argv)
{

    int a, b; 
    printf("Input a number: ");
    scanf("%d", &a);
    printf("Input another number: ");
    scanf("%d", &b);

    int *ap = &a;
    int *bp = &b;
    
    if (*ap < *bp)
        ap = &b;

    printf("%d is the greater one\n", *ap);


    // int a = 12, b = 6, *a_ptr, *b_ptr, max;
    // a_ptr = &a;
    // b_ptr = &b;

    // if ( *a_ptr > *b_ptr )
    //     max = *a_ptr;
    // else
    //     max = *b_ptr;

    // printf("%d is the maximum number\n", max);

    return 0;
}