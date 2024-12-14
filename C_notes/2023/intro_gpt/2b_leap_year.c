#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[])
{    
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    int current_year = tm->tm_year+1900;

    if ( current_year % 4 == 0 )
        printf("%d is a leap year", current_year);
    else
        printf("%d is not a leap year", current_year);
    return 0;
}
