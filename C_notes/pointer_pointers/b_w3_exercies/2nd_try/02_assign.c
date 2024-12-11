#include <stdio.h>

int main(){
    
    int m = 29;
    printf("adrss of m: %p\n", &m);
    printf("value of m: %d\n", m);
    
    int *ab = &m;
    printf("Now ab is assigned with the address of m\n");
    printf("adrss of ab: %p\n", ab);
    printf("value of ab: %d\n", *ab);

    m = 34;
    printf("The value of m assigned to 34 now\n");
    printf("adrss of ab: %p\n", ab);
    printf("value of ab: %d\n", *ab);

    *ab = 7;
    printf("The pointer variable ab is assigned with the value 7 now\n");
    printf("adrss of m: %p\n", &m);
    printf("value of m: %d\n", m);

    return 0;    
}
