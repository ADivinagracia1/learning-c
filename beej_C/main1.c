#include <stdio.h>
#include <stdlib.h>

void foo ( char * bar ) {
    printf("%s\n", bar);
}

int main(void) {

    foo ( "Hello World");
    return 0;
}