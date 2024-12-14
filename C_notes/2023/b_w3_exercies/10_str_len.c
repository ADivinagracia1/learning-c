#include <stdio.h>

#define LEN 20

int findLengthNaiive( char * str )
{
    int count = 0;
    
    // while ( *str != NULL ){ DONT USE 'NULL'
    while ( *str != '\0' ){
        str++;      // increment int pointer
        count++;    // increment counter
    }
    return count;
}

int main(int argc, char **argv)
{
    // // Using ARGV as input
    // char * buff[LEN];
    // strncpy(buff, argv[1], LEN);

    char * str;
    printf("input a string: ");
    scanf("%s", str);

    int ans = findLengthNaiive( str );

    printf("There are %d characters\n", ans);
    
    return 0;
}


// comparison between pointer and integer ('char' and 'void *') [-Wpointer-integer-compare]
// char word[] = "penis";
// if ( word[5] == NULL ) {
//     printf("%c\n", word[5]);
//     printf("%c\n", word[4]);
//     printf("inside if-");
// }