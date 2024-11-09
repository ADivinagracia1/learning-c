#include <stdio.h>

int main(void){

    int num = 5;
    int *pt;

    pt = &num;
    printf("%d %p %p %d\n", num, &num, pt, *pt);

    *pt = 12;
    printf("%d %p %p %d\n", num, &num, pt, *pt);

    

    return 0;
}