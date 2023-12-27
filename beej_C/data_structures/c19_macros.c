#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// void penis(){
//     printf("This function: %s\n", __func__);
// }
// int main(void)
// {
//     penis();
//     printf("This file: %s\n", __FILE__);
//     printf("This line: %d\n", __LINE__);
//     printf("Compiled on: %s |||| %s\n", __DATE__, __TIME__);
//     printf("C Version: %ld\n", __STDC_VERSION__);
//     return 0;
// }


// #define QUADP(a, b, c) ((-(b) + sqrt((b) * (b) - 4 * (a) * (c))) / (2 * (a)))
// #define QUADM(a, b, c) ((-(b) - sqrt((b) * (b) - 4 * (a) * (c))) / (2 * (a)))
// #define QUAD(a, b, c) QUADP(a, b, c), QUADM(a, b, c)
// int main(void)
// {
//     printf("2*x^2 + 10*x + 5 = 0\n");
//     printf("x = %f or x = %f\n", QUAD(2, 10, 5));
// }


// // Combine the first two arguments to a single number,
// // then have a commalist of the rest of them:
// #define X(a, b, ...) (10*(a) + 20*(b)), __VA_ARGS__
// int main(void)
// {
//     printf("%d %f %s %d\n", X(5, 4, 3.14, "Hi!", 12));
// }

// Multiline macros end with a backslash 
#define ASSERT(c, m) \
do { \
    if (!(c)) { \
        fprintf(stderr, __FILE__ ":%d: assertion %s failed: %s\n", \
                        __LINE__, #c, m); \
        exit(1); \
    } \
} while(0)
int main(void)
{
    int x = 30;

    ASSERT(x < 20, "x must be under 20");
}
