#include <stdio.h>
#include <stdint.h>

typedef struct {
    uint32_t id;
    uint8_t dlc;
    float data;
}CAN_Message;


void swampNums(int* n1, int* n2){
    int buff = *n1;
    *n1 = *n2;
    *n2 = buff;
}


int main(void){    
    
    int num = 151;
    int *pt;
    pt = &num;

    printf("n value is %d\n", num);
    *pt = 500;
    printf("n value is %d\n", num);

    int a = 6, b =10;
    printf("a = %d, b = %d\n", a, b);
    swampNums(&a, &b);
    printf("a = %d, b = %d\n", a, b);

    return 0;
}