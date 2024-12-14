#include <stdio.h>

int main(int argc, char** argv)
{
    int a = 5, b = 6;
    int* a_ptr = &a;
    int* b_ptr = &b;

    int c = *a_ptr + *b_ptr;

    printf("(a) val: %d\t\t\t adr: %p\n", a, &a);
    printf("(b) val: %d\t\t\t adr: %p\n", b, &b);
    printf("(a_ptr) val: %p\t adr: %p\n", a_ptr, &a_ptr);
    printf("(b_ptr) val: %p\t adr: %p\n", b_ptr, &b_ptr);
    printf("(c) val: %d\t\t\t adr: %p\n", c, &c);

    printf("%d + %d = %d\n", a, b, c);

    return 0;
}
