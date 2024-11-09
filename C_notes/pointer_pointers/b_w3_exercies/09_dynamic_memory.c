#include <stdio.h>
#include <stdlib.h>

void printArray( int *arr, int size )
{
    printf("array: ");
    for ( int i = 0; i < size; i++ ){
        printf("%d,", *arr);
        arr++;
    }
    printf("\n");
}

// Testing first time use of malloc outside main
void mallocTest( int *num, int size )
{   
    for ( int i = 0; i < size; i++ )
        printf("%d\t%p\n", *(num+i), (num+i));
}

// Naiive check, have a 'max' variable, return it
int checkBig( int *num, int size )
{
    int max = *num;
    for ( int i = 0; i < size; i++ ){
        if ( *(num+i) > max )
            max = *(num+i);
    }
    return max;
}

// Pass by reference, altering original array made in main()
// --> Moves the max number to the front of the array 
// so when the array is called, the max number is on the front of the array
void checkBigMalloc( int *num, int size )
{
    for ( int i = 0; i < size; i++ ){
        if ( *num < *(num+i) ){
            *num = *(num+i);
        }
            printf("%d) ", i);
            printArray( num, size );
        // else
        //     printf("[%d]: not greater than prev\n", i);

        // printf("[%d]: greater than prev\t", i);
        // printf("max val: %d\tmax adr: %p\n",*num, num );
    }
}



int main(int argc, char** argv)
{
    int *num; // Malloc Array
    int i, n;
    printf("Put how many numbers to put into the heap: ");
    scanf("%d", &n);
    num = malloc(n*sizeof(int));
    for ( i = 0; i < n; i++ ){
        printf("number[%d]: ", i);
        scanf("%d", num+i);
        // printf("%p\n", num+i);
        printArray( num, n );
    }
    // mallocTest( num, n );
    // int max = checkBig( num, n );
    checkBigMalloc( num, n );
    printf("%d is the largest number", *num);
    free(num);

    return 0;
}

