#include <stdio.h>

int main(int argc, char const *argv[])
{
    char alph[27], *alph_ptr; 
    
    alph_ptr = alph;
    for (int i = 0; i < 26; i++ )
    {
        *alph_ptr = 'A' + i;
        alph_ptr++;
    }

    printf("Alphabet using arrays: ");
    for (int i = 0; i < 26; i++)
        printf("%c ", alph[i] );


    printf("\nAlphabet using pointers: ");
    alph_ptr = alph;
    for (int i = 0; i < 26; i++){
        printf("%c ", *alph_ptr );
        alph_ptr++;
    }


    return 0;
}
