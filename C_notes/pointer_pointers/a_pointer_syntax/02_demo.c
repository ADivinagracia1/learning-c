#include <stdio.h>

int main(int argc, char** argv)
{

    int m; 
    int *ab;

    m = 29;
    printf("adr of m: %p\n", &m);
    printf("val of m: %d\n", m);
    
    ab = &m;
    printf("Now ab is assiged with the address of m\n");
    printf("adr of ab: %p\n", &ab);
    printf("val of ab: %p\n", ab);
    

    return 0;
}