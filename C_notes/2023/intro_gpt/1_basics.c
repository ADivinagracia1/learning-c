#include <stdio.h>

void hello_world();
void square();
void sum();
void print_string();
void odd_even();
void max_of_3();

int main(){

    // hello_world();
    // square();
    print_string();
    // sum();
    // odd_even();
    // max_of_3();
    return 0;
}

void hello_world(){
    printf("Hello World!");
}

void print_string(){
    char str[10];
    scanf("%s", str);
    printf("%s\n", str);
}

void square(){
    short num;
    printf("Enter a number: ");
    scanf("%hd", &num);
    printf("The square is %d", num*num);
}

void sum(){
    int a, b;
    printf("Enter a number: ");
    scanf("%d", &a);
    printf("Enter another number: ");
    scanf("%d", &b);
    printf("The sum is %d", a+b);
}

void odd_even(){
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    // uses bitwise operation --> Masks the LSB
    if( (num & 0b1) == 1 )  
        printf("%d is even", num);
    else
        printf("%d is odd", num); 
}

void max_of_3(){

    int a, b, c;

    printf("Enter 3 numbers: ");
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    int max = a;

    if( max < b )
        max = b;
    if( max < c )
        max = c;
    
    printf("The largest number is %d", max);

}