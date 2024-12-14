#include <stdio.h>

void findLargest(int *arr_ptr, int sz)
{
    for (size_t i = 0; i < sz; i++)
    {
        if ( *arr_ptr < *(arr_ptr+i) )
            *arr_ptr = *(arr_ptr+i);
    }
    
}

int main(int argc, char const *argv[])
{
    int size, array[size];

    printf("Choose array size: ");
    scanf("%d", &size);

    for ( int i = 0; i < size; i++ )
    {
        printf("array[%d]: ", i);
        scanf("%d", &array[i]);
    }

    findLargest(array, size);
    printf("%d is the largest\n", *array);


    return 0;
}
