#include <stdio.h>

#define MAX_SIZE 20

void StringConcatenate(char *s1, char *s2){
    while(*s1 != '\0'){ *s1++; }
    while(*s2 != '\0'){
        *s1 = *s2;
        *s1++;
        *s2++;
    }
    *s1 = '\0';
}


int main(){
    
    char str1[MAX_SIZE], str2[MAX_SIZE];

    printf("enter 1st string: ");
    scanf("%s", str1);
    printf("enter 2nd string: ");
    scanf("%s", str2);

    StringConcatenate(str1, str2);

    printf("concatenated: %s\n", str1);

    return 0;
}