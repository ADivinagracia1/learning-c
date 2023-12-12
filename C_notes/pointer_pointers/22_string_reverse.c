#include <stdio.h>
#define SIZE 50

int main(int argc, char const *argv[])
{
    char word[SIZE] = "", rev_word[SIZE] = "";
    char *word_pt = word, *rev_pt = rev_word;

    printf("input a word: ");
    scanf("%s", word);

    printf("word: %s\n", word);

    // Go to end of word
    while ( *word_pt != '\0' ) word_pt++;
    // note: *word_pt lands at end of memory: '\0'

    // Walk backwards of the original string, assign it to new array
    while ( *word_pt != *word ) {
        word_pt--;
        // printf("%c, ", *word_pt);
        *rev_pt = *word_pt; 
        rev_pt++;
    }

    printf("revd: %s\n", rev_word);

    return 0;


    //// FIRST SOLUTION
    // char word[50], rev_word[50];
    // char *ptr = word;
    // char *revptr = rev_word;

    // printf("input a string: ");
    // scanf("%s", word);

    // printf("!: %s\n",word);

    // // Reach the end of the word
    // int i = 0;
    // while ( *ptr )
    // {
    //     ptr++;
    //     i++;
    // }

    // while ( i > 0 )
    // {
    //     ptr--; 
    //     *revptr = *ptr;
    //     revptr++;
    //     i--;
    // }

    // *revptr = '\0';
    // printf("i: %s\n",rev_word);


    // return 0;
}
