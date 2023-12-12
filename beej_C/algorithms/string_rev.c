#include <stdio.h>
#include <stdlib.h>

void foo ( char * bar ) {
    printf("%s\n", bar);
}

int main(void) {

    char *buff, *out;
    printf("input string: ");
    scanf("%s", buff);

    char *in_ptr = buff, *out_ptr = out;

    while ( *in_ptr != '\0' ) {
        printf("%c-", *in_ptr);
        in_ptr++;
    }
    // while ( *in_ptr != *buff ) {
    //     in_ptr--;
    //     *out_ptr = *in_ptr;
    //     out_ptr++;
    // }

    // printf("out: %s\n", out);

    return 0;
}