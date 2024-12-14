#include <stdio.h>

#define LEN 20

void arrayPointerPrint(char *a_ptr); // prints contents of array

void myCat(char *a_ptr, char *b_ptr)
{
    while( *a_ptr != '\0' )
    {
        // printf("%p, %c\n", a_ptr, *a_ptr);
        a_ptr++;
    }

    // printf("%p\n", a_ptr);

    while ( *b_ptr != '\0' )
    {
        // printf("%c\n", *b_ptr);
        *a_ptr = *b_ptr;
        a_ptr++; 
        b_ptr++;
    }
    
    *a_ptr = '\0';
}

int main(int argc, char **argv)
{
    char str1[LEN], str2[LEN];

    printf("1st: ");
    scanf("%s", str1);
    printf("2nd: ");
    scanf("%s", str2);

    myCat(str1, str2);

    printf("Cat: %s\n", str1);
    return 0;
}

void arrayPointerPrint(char *a_ptr)
{
    while( *a_ptr != '\0' )
    {
        printf("%c\n", *a_ptr);
        a_ptr++;
    }
}