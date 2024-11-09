#include <stdio.h>

void printArray(int array[], int size)
{
    printf("[");
    for ( int i = 0; i < size; i++ )
        printf("%d, ", *(array+i));
    printf("]\n");
}

void reversedArray(int array[], int size)
{
    int *arr_ptr = array+size-1;
    printf("[");
    for ( int i = 0; i < size; i++ ){
        printf("%d, ", *arr_ptr);
        arr_ptr--;
    }
    printf("]\n");
}

int main(int argc, char const *argv[])
{
    int sz, arr[sz];
    printf("How big is your array? ");
    scanf("%d", &sz);

    for (int i = 0; i < sz; i++ ){
        printf("arr[%d]: ", i);
        scanf("%d", arr+i);
    }

    printf("In order: ");
    printArray(arr, sz);

    printf("Reversed: ");
    reversedArray(arr, sz);

    return 0;
}
