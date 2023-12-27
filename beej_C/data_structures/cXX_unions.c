#include <stdio.h>
#include <stdlib.h>

union Data {
    // Comment out the following lines in the union
    int i;
    float f;
    double D;
    char str[20];
};
 
int main( ) {

    union Data data;        

    printf( "Memory size occupied by data : %lu\n", sizeof(data));

    data.i = 2;
    printf("%d\n", data.i);
   
    data.f = 2.2;
    printf("%f\n", data.f);
   
    data.D = 20000000000000000;
    printf("%f\n", data.D); 

    return 0;
}