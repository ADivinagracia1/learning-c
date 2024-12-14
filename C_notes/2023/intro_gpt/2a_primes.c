#include <stdio.h>
#include <math.h> 
#include <time.h>  

int checkPrime( int num );

int main(){

    clock_t start = clock();

    for( int i = 1; i < 1000001; i++){
        if( checkPrime(i) )
            printf("%d, ", i);
    }

    clock_t end = clock();
    printf("\n%lf has passed", (double)(end - start)/CLOCKS_PER_SEC);

    return 0;
}

int checkPrime( int num ){

    if ( num == 1 || num == 2)
        return 1;

    for ( int i = 2; i < ceil(sqrt(num)); i++ ){
        if ( num % i == 0 )
            return 0;
    }

    return 1;
}