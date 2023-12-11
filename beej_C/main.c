#include <stdio.h>
#define SIZE 50

struct TestStruct {
    int a;
    int b;
    int c;
    int arr[0];
};

// REVERSE A STRING (CLASSIC)
int main(void){

    // Struct: 12 Bytes + 
    // struct TestStruct *meep = (struct TestStruct*)malloc(sizeof(struct TestStruct) + sizeof(int) * 10 );

    printf("Struct Size: %ld\n", sizeof(struct TestStruct));
    return 0;
}