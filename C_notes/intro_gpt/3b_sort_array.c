#include <stdio.h>

#define SIZE 6

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectoinSort(int array[], int size)
{
    int i, j, min;
    for ( i = 0; i < size; i++)
    {
        min = i;

        for ( j = i+1; j < size; j++) {
            if ( array[j] < array[min] )
                min = j;
        }

        if ( i != min )
            swap(&array[i], &array[min]);

    }
    
}

void printArray( int array[], int size )
{
    for (size_t i = 0; i < size; i++)
        printf("%d, ", array[i]);
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int array[SIZE] = {5, 2, 7, 12, 6, 4};

    printArray(array, SIZE);
    selectoinSort(array, SIZE);
    printArray(array, SIZE);


    return 0;
}
