#include <stdio.h>

#define MAX_SIZE 10

void matrixMultiplication(int (*mat1)[MAX_SIZE], int (*mat2)[MAX_SIZE], int (*res)[MAX_SIZE], int rows1, int cols1, int rows2, int cols2 )
{
    for ( int i = 0; i < rows1; i++ ){
        for ( int j = 0; j < cols2; j++ ){
            res[i][j] = 0;
            for ( int k = 0; k < cols1; k++)
                res[i][j] += mat1[i][k] * mat2[k][j];
        }
    }
}

void displayMatrix(int mat[][MAX_SIZE], int rows, int cols)
{
    int i, j;
    
    for (i = 0; i < rows; i++) {
        printf("[ ");
        for (j = 0; j < cols; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("]\n");
    }
}

int main(int argc, char const *argv[])
{
    int mat1[MAX_SIZE][MAX_SIZE], mat2[MAX_SIZE][MAX_SIZE], res[MAX_SIZE][MAX_SIZE];
    int rows1, cols1, rows2, cols2, i, j;

    // Input matrix 1
    printf("Enter the number of rows for matrix 1: ");
    scanf("%d", &rows1);
    printf("Enter the number of columns for matrix 1: ");
    scanf("%d", &cols1);
    printf("Enter the elements of matrix 1:\n");
    for ( i = 0; i < rows1; i++ )
        for ( j = 0; j < cols1; j++ )
            scanf("%d", &mat1[i][j]);
    
    // Input matrix 2
    printf("Enter the number of rows for matrix 2: ");
    scanf("%d", &rows2);
    printf("Enter the number of columns for matrix 2: ");
    scanf("%d", &cols2);
    printf("Enter the elements of matrix 1:\n");
    for ( i = 0; i < rows2; i++ )
        for ( j = 0; j < cols2; j++ )
            scanf("%d", &mat2[i][j]);

    if ( rows1 != cols2 )
    {
        printf("Columns of the 1st matrix must be equal to rows of the 2nd matrix\n");
        return 0;
    }

    displayMatrix(mat1, rows1, cols1);
    displayMatrix(mat2, rows2, cols2);
    matrixMultiplication(mat1, mat2, res, rows1, cols1, rows2, cols2);

    displayMatrix(res, rows1, cols2);
    
    return 0;
}
