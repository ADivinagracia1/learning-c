#include <stdio.h>
#include <stdlib.h>

void stringReversal(char *inp, char *out){

    char *a_head = inp, *b_head = out;
    while(*inp != '\0'){ *inp++; }
    while (*inp != *a_head){
        *inp--;
        *out = *inp;
        *out++;
    }
    *out = '\0';
}

char * stringReversalRef(char *inp){

    char *end = inp;
    while ( *end != '\0') { end++; printf("%c", *inp); } end--;

    // char *out = (char*)malloc((end - inp + 2) * sizeof(char));
    // if (out == NULL) return NULL;

    // while (end >= inp){
    //     printf("%p - %p", end, inp);
    //     end--;
    // }

}

int main(){
    
    char *input, *output;
    scanf("%s", input);

    // stringReversal(input, output); // Pass by reference
    char *out = stringReversalRef(input);

    printf("%s\n", output);

    return 0;
}