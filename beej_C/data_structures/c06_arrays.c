// Source:
//  https://beej.us/guide/bgc/html/split/arrays.html#arrays

#include <stdio.h>
#include <stdlib.h>

void printArray(int *arr){
    printf("[ ");  
    // ++arr; // for expressions
    // ++arr;
    while ( *arr != 0 ) {
        printf("%d", *arr);
        ++arr;
        if ( *arr != 0 ) {
            printf(", ");
        }
    }    
    printf(" ]\n");
}

void printArrayValue(int arr[], int size){
    printf("[ ");
    for (int i = 0; i < size; ++i) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf(" ]\n");
}

void TestForPrintingArray(){
    int a[5] = {22, 37, 3490};
    int b[5] = {22, 37, 3490, 0, 0};
    int c[100] = {0};

    int *a_pt = a, *b_pt = b, *c_pt = c;

    printf("Arrays traversed by pointers\n");
    printArray(a_pt);
    printArray(b_pt);
    printArray(c_pt);

    printf("\nArrays traversed by iteration\n");
    printArrayValue(a, 5);
    printArrayValue(b, 5);
    printArrayValue(c, 100);
}

#define COUNT 5


// ===================== ARRAYS AND POINTERS IN FUNCTION PARAMETERS =====================

void times2(int *a, int len){
    for (int i=0; i < len; i++)
        printf("%d-", a[i] * 2);
    printf("\n");
}

void times3(int a[], int len){
    for (int i=0; i < len; i++)
        printf("%d-", a[i] * 3);
    printf("\n");
}

void times4(int a[5], int len){
    for (int i=0; i < len; i++)
        printf("%d-", a[i] * 4);
    printf("\n");
}


// ===================== PASSING ARRAYS AS PARAMETERS =====================

void mult_elem_2(int *a, int len){
    for (int i=0; i<len; i++)
        a[i]*=2;
}

// MULTIDEMENTONAL ARRAY AS PARAMETERS
void print_2D_array(int a[2][3]){
    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 3; col++)
            printf("%d ", a[row][col]);
        printf("\n");
    }
}

int main(void){

    // TestForPrintingArray();

// INSERTING PROPERTY
    // int a[COUNT] = {[COUNT-3]=3, 2, 1};
    // int* a_ptr = a;
    // printArray(a_ptr);

// ARRAYS AND POINTERS IN FUNCTION PARAMETERS
    // int x[5] = {11, 22, 33, 44, 55};
    // times2(x, 5);
    // times3(x, 5);
    // times4(x, 5);

// PASSING ARRAYS AS PARAMETERS
    // int x[5] = {1, 2, 3, 4, 5};
    // mult_elem_2(x, 5);
    // for (int i = 0; i < 5; i++)
    //     printf("%d\n", x[i]);  // 2, 4, 6, 8, 10!

// MULTIDEMENTONAL ARRAY AS PARAMETERS
    int x[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    print_2D_array(x);
    return 0;
}