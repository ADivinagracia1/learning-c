#include <stdio.h>

void countVowels(char* str_ptr, int *v, int *c)
{
    *v = 0, *c = 0;
    while ( *str_ptr != '\0' )
    {
        switch ( *str_ptr )
        {
        case 'a': (*v)++; break;
        case 'e': (*v)++; break;
        case 'i': (*v)++; break;
        case 'o': (*v)++; break;
        case 'u': (*v)++; break;
        default: (*c)++; break;
        }
        str_ptr++;
    }
}

int main(int argc, char** argv)
{
    char * str;
    int vowl, cons;
    printf("input a string: ");
    scanf("%s", str);
    countVowels(str, &vowl, &cons);
    printf("%d vowels\n", vowl);
    printf("%d consonants\n", cons);

    return 0;
}
