#include <stdio.h>
#include <stdlib.h>

// int main(void){
//     // different outputs in 64 and 32 bit compilers
//     int a = 3;
//     int b = ++a + a++ + --a; // unsequenced modifications
//     // a gets incremented, a gets incremented, and then decremented --> a= 4, 5, 4 --> 4 + 4 + 4 = 12
//     printf("%d \n", b);
//     return 0;
// }

int main(void){
    int a, b = 1, c = 1;
    a = sizeof(c = ++b + 1); 
    // sizeof is a compile time operation
    // ++b and the c assignment will not affect anything when running ./a.out
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n", c);
    return 0;
}

// int main(void){
//     /*
//         Pointers store values in READ ONLY MEMORY
//         Arrays store values in WRITABLE MEMORY
//     */

//     // char *p = "SAN";
//     // *p = 'A';
//     // printf("%c\n", *p); // No answer, SEGMENTATION FAULT

//     // // WORKING VERSION OF THE CODE:
//     // char q[] = "SAN";
//     // q[0] = 'A';
//     // printf("%s\n", q);
// }
