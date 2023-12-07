#include <stdio.h>
#define SIZE 50

// REVERSE A STRING (CLASSIC)
int main(void){

    char word[SIZE] = "", rev_word[SIZE] = "";
    char *word_pt = word, *rev_pt = rev_word;

    printf("input a word: ");
    scanf("%s", word);

    printf("word: %s\n", word);

    // Go to end of word
    while ( *word_pt != '\0' ) word_pt++;

    // Walk backwards of the original string, assign it to new array
    while ( *word_pt != *word ) {
        word_pt--;
        // printf("%c, ", *word_pt);
        *rev_pt = *word_pt; 
        rev_pt++;
    }

    printf("revd: %s\n", rev_word);

    return 0;
}