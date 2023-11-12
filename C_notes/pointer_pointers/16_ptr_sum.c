#include <stdio.h>

int sum(int array[], int size)
{
    int sum = 0;
    for ( int i = 0; i < size; i++ )
    {
        sum += *(array+i);
    }
    return sum;
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

    printf("sum = %d\n", sum(arr, sz));


    return 0;
}
