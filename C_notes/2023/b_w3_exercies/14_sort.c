#include <stdio.h>

void printArray( int array[], int size )
{
    printf("[ ");
    for ( int i = 0; i < size; i++ )
        printf("%d, ", *(array+i));
    printf("]\n");
}

void swap(int *a, int *b)
{
    int buff = *a;
    *a = *b;
    *b = buff;
    printf("s ");
}

void insertionSort( int array[], int size )
{
    int i, j;
    for (i = 0; i < size; i ++)
    {
        for ( j = i+1; j < size; j++)
        {
            if ( *(array+i) > *(array+j) )
                swap(array+i, array+j);
            else
                printf("_ ");

            printf("i=%d, j=%d\t", i, j);
            printArray(array, size);
        }
        
    }
}

int main(int argc, char const *argv[])
{
    int sz, arr[sz];

    printf("How big is your array? ");
    scanf("%d", &sz);

    for (int i = 0; i < sz; i++) {
        printf("arr[%d]: ", i);
        scanf("%d", arr);
    }

    printf("Start Array: \t");
    printArray(arr, sz);

    insertionSort(arr, sz);

    printf("Sorted Array: \t");
    printArray(arr, sz);

    return 0;
}
