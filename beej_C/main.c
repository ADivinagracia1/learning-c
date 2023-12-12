#include <stdio.h>
#define SIZE 50

void foo(int *x)
{
    printf("%zu\n", sizeof(*x));     // 8?! What happened to 48?
    printf("%zu\n", sizeof(int));  // 4 bytes per int

    printf("%zu\n", sizeof(*x)/ sizeof(int));  // 8/4 = 2 ints?? WRONG.
}

int main(void){

    // Struct: 12 Bytes + 
    // struct TestStruct *meep = (struct TestStruct*)malloc(sizeof(struct TestStruct) + sizeof(int) * 10 );
    int arr[12] = { 0 };

    printf("size: %zu\n", sizeof(int [48]));
    printf("num: %d\n", 48 * 4);

    // foo(arr);
    return 0;
}