#include <stdio.h>

int main(int argc, char const *argv[])
{
    char word[50], rev_word[50];
    char *ptr = word;
    char *revptr = rev_word;

    printf("input a string: ");
    scanf("%s", word);

    printf("!: %s\n",word);

    // Reach the end of the word
    int i = 0;
    while ( *ptr )
    {
        ptr++;
        i++;
    }

    while ( i > 0 )
    {
        ptr--; 
        *revptr = *ptr;
        revptr++;
        i--;
    }

    *revptr = '\0';
    printf("i: %s\n",rev_word);


    return 0;
}
