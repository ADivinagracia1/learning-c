#include <stdio.h>

int main(int argc, char** argv)
{
    int m = 300;                                                                                                      
    float fx = 300.600006;                                                                                              
    char cht = 'z';

    // & operator returns the ADDRESS
    printf("adr of m: %p\n",&m);
    printf("adr of fx: %p\n",&fx);
    printf("adr of cht: %p\n",&cht);

    // * operator for VALUES
    int* m_ptr = &m;                                                                                           
    float* fx_ptr = &fx;                                                                                              
    char* cht_ptr = &cht;
    printf("val of m: %d\n", *m_ptr);
    printf("val of fx: %f\n", *fx_ptr);
    printf("val of cht: %c\n", *cht_ptr);

    // Addresses of the values (aka values of the pointers)
    printf("adr of m: %p\n",m_ptr);
    printf("adr of fx: %p\n",fx_ptr);
    printf("adr of cht: %p\n",cht_ptr);

    // * and & operator for VALUES --> What does the address point to? = the value
    printf("val of m: %d\n", *(&m));
    printf("val of fx: %f\n", *(&fx));
    printf("val of cht: %c\n", *(&cht));
    


    return 0;
}