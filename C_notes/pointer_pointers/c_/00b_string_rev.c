#include <stdio.h>

void stringReversal(char *inp, char *out){

    char *a_head = inp, *b_head = out;
    while(*inp != '\0'){ 
        *inp++; 
    }
    while (*inp != *a_head){
        *inp--;
        *out = *inp;
        *out++;
    }
    *out--;
    *out = '\0';
    *out = *b_head;
}

int main(){
    
    char input[20], output[20];
    scanf("%s", input);

    stringReversal(input, output);

    printf("%s\n", output);

    return 0;
}