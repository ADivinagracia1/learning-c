#include <stdio.h>

int main(int argc, char** argv)
{
    int size;
    printf("Enter size of the array: ");
    scanf("%d", &size);

    int array[size], i = 0;
    int* arr_ptr;
    arr_ptr = array;
    while ( i < size )
    {
        printf("array[%i] = ", i);
        scanf("%d", arr_ptr);
        arr_ptr++;
        i++;
    }

    // Contents of array
    printf("array = { ");
    for ( i = 0; i < size; i++ )
        printf("%d, ", array[i]);
    printf("}");

    return 0;
}