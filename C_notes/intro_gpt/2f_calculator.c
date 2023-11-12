#include <stdio.h>


void doAddition(int *a_ptr, int *b_ptr )
{
    printf("%d\n", *a_ptr + *b_ptr);
}

void doSubition(int *a_ptr, int *b_ptr )
{
    printf("%d\n", *a_ptr - *b_ptr);
}

void doMultiplication(int *a_ptr, int *b_ptr )
{
    printf("%d\n", (*a_ptr) * (*b_ptr));
}

void doDivison(int *a_ptr, int *b_ptr )
{
    printf("%d,r%d\n", *a_ptr + *b_ptr, 
                       *a_ptr % *b_ptr);
}

void doPowerOf(int *a_ptr, int *exponent_ptr )
{   
    int result = 1;
    for ( int i = 0; i < *exponent_ptr; i++)
        result *= *a_ptr;
    printf("%d\n", result);
}

void calculatorRun( char input, int a, int b)
{
    switch ( input )
    {
        printf("Out: ");
        case '+': doAddition(&a, &b); break;
        case '-': doSubition(&a, &b); break;
        case '*': doMultiplication(&a, &b); break;
        case '/': doDivison(&a, &b); break;
        case '^': doPowerOf(&a, &b); break;
    
        default:
            printf("restarting calculator...");
            break;
    };
}

int main(int argc, char const *argv[])
{
    char input_buffer;
    int a, b;

    printf("Welcome to the calculator!");

    for (;;)
    {
        printf("Choose operation (+, -, *, /, ^): ");
        scanf("%s", &input_buffer);
        while (getchar() != '\n');  // Clear input buffer
        if (input_buffer == 'q' ) {
            printf("Quitting the program...\n");
            break;  // Terminate the loop
        }

        printf("1st: ");
        scanf("%d", &a);
        while (getchar() != '\n');

        printf("2nd: ");
        scanf("%d", &b);
        while (getchar() != '\n');

        calculatorRun(input_buffer, a, b);

    }
    return 0;
}


// int main(int argc, char const *argv[])
// {
//     char inp_buff[2];
//     float num_buff;
//     int a, b;

//     while (1) {    

//         printf("Welcome to your calculator\n");
//         printf("q1: ");
//         scanf("%d", &a);
//         while (getchar() != '\n');



//         // printf("Welcome to your calculator\n");
//         // printf("q1: ");
//         // scanf("%d", &a);
//         // while (getchar() != '\n');

//         // if (scanf("%s", inp_buff) != 1) {
//         //     printf("Invalid input. Please try again.\n");
//         //     while (getchar() != '\n');  // Clear input buffer
//         // } else {
//         //     if (inp_buff[0] == 'q' && inp_buff[1] == '\0' ) {
//         //         printf("Quitting the program...\n");
//         //         break;  // Terminate the loop
//         //     }
//         //     printf("Input: %s\n", inp_buff);
//         // }
//     }

//     // printf("Welcome to your calculator\n");
//     // printf("q1: ");
//     // scanf("%d", &a);
//     // while (getchar() != '\n');

//     // printf("q2: ");
//     // scanf("%c", &c_buff);
//     // while (getchar() != '\n');

//     // printf("q3: ");
//     // scanf("%d", &b);
//     // while (getchar() != '\n');


    
//     // switch ( c_buff )
//     // {
//     //     case '+': doAddition(&a, &b); break;
//     //     case '-': doSubition(&a, &b); break;
//     //     case '*': doMultiplication(&a, &b); break;
//     //     case '/': doDivison(&a, &b); break;
//     //     case '^': doPowerOf(&a, &b); break;
    
//     //     default:
//     //         break;
//     // };
    
//     //-----------------------------

//     // printf("Choose operation (+, -, *, /, ^, √): ");

//     //scanf("%c", &input);

//     // printf("%c\n", input);
//     // printf("%c\n", *input_ptr);

//     // char input[100];  // Assuming input is a string
    


//     // for(;;)
//     // {
//     //     printf("Choose operation (+, -, *, /, ^, √): ");
        
//     //     if ( scanf("%c", &input) == 0 ){
//     //         printf("yes!");
//     //         // while ( getchar() != '\n'); // Clear input buffer
//     //     }
//     //     else if ( scanf("%c", &input) == 'q' || scanf("%c", &input) == '\n' )
//     //     {
//     //         printf("quit");
//     //         break;
//     //     }
        


//     //     // switch (input)
//     //     // {
//     //     // case '+':
//     //     //     void doAddition(&a, &b);
//     //     //     break;
//     //     // case '-':
//     //     //     void doSubition();
//     //     //     break;
//     //     // case '*':
//     //     //     void doMultiplication();
//     //     //     break;
//     //     // case '/':
//     //     //     void doDivison();
//     //     //     break;
//     //     // case '^':
//     //     //     void doPowerOf();
//     //     //     break;
//     //     // case '√':
//     //     //     void doSqRoot();
//     //     //     break;
        
//     //     // default:
//     //     //     break;
//     //     // }

//     // }
//     printf("Goodbye");

//     return 0;
// }


