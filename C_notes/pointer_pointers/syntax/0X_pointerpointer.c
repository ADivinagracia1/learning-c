#include <stdio.h>

int main(void){
    
    char *p = "Hello World";
    char **p1 = &p;

                                    // What is the value of each of these pointers?
    printf("p = %s\n", p);          // Full string 
    printf("*p = %c\n", *p);        // Single char
    printf("p1 = %p\n", p1);        // Address of p (&p)
    printf("*p1 = %p\n", *p1);      // Address of *p, address of the single character
    printf("**p1 = %c\n", **p1);    // point to the address of the single character [Aka, the single char]
    printf("&p = %p\n", &p);
    printf("=========================================\n");

    // Pointer to pointer to pointer
    char ***p2 = &p1;
    printf("p2 = %p\n", (void *)p2);        // Address of p1
    printf("*p2 = %p\n", (void *)*p2);      // equivalent to p1 
    printf("**p2 = %p\n", (void *)**p2);    // equivalent to *p1
    printf("***p2 = %c\n", ***p2);          // equivalent to **p1
    printf("=========================================\n");

    // Pointer to pointer to pointer to pointer
    char ****p3 = &p2;
    printf("p3 = %p\n", (void *)p3);        // Address of p2
    printf("*p3 = %p\n", (void *)*p3);      // equivalent to p2, adr of p1
    printf("**p3 = %p\n", (void *)**p3);    // equivalent to *p2
    printf("***p3 = %p\n", (void *)***p3);  // equivalent to **p2
    printf("****p3 = %c\n", ****p3);        // equivalent to ***p2
    printf("=========================================\n");


    while ( *p != '\0' ) {
        printf("%c-", (*p));
        p++;
    }
    // p ends at nullptr


    return 0;
}