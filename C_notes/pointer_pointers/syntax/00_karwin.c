// Karwin = https://karwin.blogspot.com/2012/11/c-pointers-explained-really.html?m=1

#include <stdio.h>

void passByValue(int x);
void passByRef(int *x);

int main()
{
    int n = 151;
    int *p;

    p = &n;

    /*
    Address:     :     Value at that address:
            |----|
    0x5100  | 151|  n
            |----|
    0x5104  |5100|  p
            |----|
    0x5108  |   ?|
            |----|
                :
                :
    */
    
    // 2 ways to print 'n'
    printf("n value is %d\n", n);
    printf("n value is %d\n", *p);

    // 2 ways to print the address of 'n'
    printf("n address is %p\n", &n);
    printf("n address is %p\n", p);

    // Show the address of p
    printf("p address is %p\n", &p);

    printf("=========================================\n");

    char name[] = "Milk";
    char *g;
    int *h;

    g = name; // char pointer, good!
    h = name; // int pointer, UNACCEPTABLE (still chill tho)

    /*
    
            |----|
    0x5100  |'M' |  "name" is an address constant that has value hex 5100
            |----|
    0x5101  |'i' |  char: 1 byte
            |----|
    0x5102  |'l' |  char: 1 byte
            |----|
    0x5103  |'k' |  char: 1 byte
            |----|
    0x5104  |\0  |  char: 1 byte
            |----|
    0x5105  |5100|  g is a pointer: 1 word --> char = GOOD
            |----|
    0x5109  |5100|  h is a pointer: 1 word --> int = UNACCEPTABLE
            |----|

            g = name;

    */

    // incrementing addresses
    printf("0: %c", *g);
    printf(" --> adr %p\n", g);
    g++; // jump 1 word
    printf("1: %c", *g);
    printf(" --> adr %p\n", g);
    g++; // jump 1 word
    printf("2: %c", *g);
    printf(" --> adr %p\n\n", g);

    printf("0: %c", *h);
    printf(" --> adr %p\n", h);
    h++; // jumps 4 words 
    printf("4: %c", *h);
    printf(" --> adr %p\n", h);
    h++; // jumps 4 words 
    printf("8: %c", *h);
    printf(" --> adr %p\n", h);

    printf("=========================================\n");

    int m = 151;

    printf("(main)\tvalue: %d\taddr: %p\n", m, &m);
    passByValue(m);
    passByRef(&m);
    printf("(main)\tvalue: %d\taddr: %p\n", m, &m);


    return 0;
}

void passByValue(int x)
{
    /*
    Function copies the value and puts it into a new address
            |---|
    0x5100  |151|  n is an integer
            |---|
    0x5104  |151|  x is another integer
            |---|
    */  

    printf("(value)\tvalue: %d\taddr: %p\n", x, &x);
}

void passByRef(int *x)
{
    /*
           |----|
    0x5100 | 451|  n is an integer 
           |----|
    0x5104 |5100|  x is a pointer to int
           |----|

    */

    printf("(ref)\tvalue: %d\taddr: %p\n", *x, x);
    *x = 500; // Assigned to the address

}