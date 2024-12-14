/*
The permutations of the string are :                                                                         
abcd  abdc  acbd  acdb  adcb  adbc  bacd  badc  bcad  bcda  bdca  bdac  cbad  cbda  cabd  cadb  cdab  cdba  db
ca  dbac  dcba  dcab  dacb  dabc
*/

#include <stdio.h>

void permutateString(char *str, int left, int right);
void permutateString(char *cht, int stno, int endno);
void swapNums(char *p1, char *p2);

int main(int argc, char** argv)
{
    char example[] = "abcd";
    char * ex_ptr = example;
    int size = sizeof(example) / sizeof(example[0]) - 1;

    printf("str: \"%s\" has %d characters\n", example, size);
    permutateString(example, 0, size - 1);
    return 0;
}

void permutateString(char *str, int left, int right)
{
    if ( left == right )
        printf("%s ", str);
    for ( int i = left; i <= right; i++ )
    {  
        swapNums(str+left, str+i);
        permutateString(str, left+1, right);
        swapNums(str+left, str+i);
    }
}

void swapNums( char *p1, char *p2 )
{
    char buff = *p1;
    *p1 = *p2;
    *p2 = buff;
}
