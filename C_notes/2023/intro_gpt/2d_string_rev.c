#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 20 

void myReversal(char inp[], char out[], size_t len);

int main(int argc, char **argv)
{
    char buff[LEN + 1] = { 0 };
    
    strncpy(buff, argv[1], LEN + 1);
    size_t inp_len = strnlen(buff, LEN+1);    
    buff[LEN] = '\0';

    char reversed_string[inp_len]; 


    printf("standard output: %s\n", buff); 
    myReversal(buff, reversed_string, inp_len);
    printf("reversed output: %s\n", reversed_string); 


    // free(the_reversed_str); // Free the memory from myReversal()

    return 0;
}

// Static Memory
void myReversal(char inp[], char out[], size_t len)
{ 
    for ( int i = 0; i < len; i++ ) { 
        printf("%c\n", inp[i]);
        out[len - i - 1] = inp[i];
    }
}

/* Dynamic Memory Solution */
// char* myReversal(char inp[], size_t len)
// {
//     // Dynamic Memory 
//     char rev[] = malloc(len);

//     for ( int i = 0; i < len; i++ ) { 
//         printf("%c\n", inp[i]);
//         rev[len - i - 1] = inp[i];
//     }

//     printf("%s", rev);
//     return rev;
// }

/*
WRONG: Stack Pointer Problem
The error wont manifest here, but the data found in this function
might be deleted on another function call. 
The local char variable "rev" ends when the function returns
--> Suceptible to being overwritten when other functions are called
// char* myReversal(char inp[], size_t len)
*/
// {
//     char rev[len];

//     for ( int i = 0; i < len; i++ ) { 
//         printf("%c\n", inp[i]);
//         rev[len - i - 1] = inp[i];
//     }

//     printf("%s", rev);
//     return rev;
// }


