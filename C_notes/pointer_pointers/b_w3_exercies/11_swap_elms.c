#include <stdio.h>

// void inputArray( int *ele )
// {
//     // wont work --> @JOSH for explanation
//     while ( *ele != '\0'){
//         printf("input number: ");
//         scanf("%d", ele);
//         ele++;
//     }
// }

// Pass by reference
void swapNumbers ( int *e1, int *e2, int *e3 )
{
    int temp;
    temp = *e3;
    *e3 = *e2; 
    *e2 = *e1;
    *e1 = temp;

}

int main(int argc, char **argv)
{
    int i = 0, SIZE = 3;
    int array[SIZE];

    for ( int i = 0; i < SIZE; i++ ){
        printf("input a num: ");
        scanf("%d", &array[i]);
    }

    printf("pre swap: %d, %d, %d\n", array[0], array[1], array[2]);
    swapNumbers( &array[0], &array[1], &array[2] );
    printf("post swap: %d, %d, %d\n", array[0], array[1], array[2]);


    return 0;
}