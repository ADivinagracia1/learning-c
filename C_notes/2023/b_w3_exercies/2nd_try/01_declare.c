#include <stdio.h>

int main(){
    

    int m=10, n, o;
    int *z = &m;

    printf("hello\n");
    printf("z stores address of m: %p\n", z);
    printf("*z stores value of m: %d\n", *z);
    printf("&m stores address of m: %p\n", &m);
    printf("&n stores address of n: %p\n", &n);
    printf("&o stores address of o: %p\n", &o);
    printf("&z stores address of z: %p\n", &z);



    return 0;
}