#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

int userInput;

void userRepeat();

void inputValid(double *num)
{
    while (1)
    {
        if (scanf("%lf", num) != 1)
        {
            printf("ERROR! Please enter a valid positive integer: ");
            while (getchar() != '\n')
                ;
        }
        else
        {
            break;
        }
    }
}

int determinant(int matrix[MAX_SIZE][MAX_SIZE], int size)
{
    int det = 0;
    int submatrix[MAX_SIZE][MAX_SIZE];
    int i, j, k, m, n;

    if (size == 1)
    {
        return matrix[0][0];
    }
    else if (size == 2)
    {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
    else
    {
        for (i = 0; i < size; i++)
        {
            m = 0;
            n = 0;
            for (j = 1; j < size; j++)
            {
                for (k = 0; k < size; k++)
                {
                    if (k == i)
                    {
                        continue;
                    }
                    submatrix[m][n++] = matrix[j][k];
                    if (n == size - 1)
                    {
                        m++;
                        n = 0;
                    }
                }
            }
            det += (i % 2 == 0 ? 1 : -1) * matrix[0][i] * determinant(submatrix, size - 1);
        }
    }
    return det;
}
int inverse(int matrix[MAX_SIZE][MAX_SIZE], int size, double inv[MAX_SIZE][MAX_SIZE])
{
    if (size == 1)
    {
        inv[0][0] = 1.0;
        return 0;
    }

    int temp[MAX_SIZE][MAX_SIZE];
    int adj[MAX_SIZE][MAX_SIZE];

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int a = 0, b = 0;
            for (int row = 0; row < size; row++)
            {
                for (int col = 0; col < size; col++)
                {
                    if (row != i && col != j)
                    {
                        temp[a][b++] = matrix[row][col];
                        if (b == size - 1)
                        {
                            b = 0;
                            a++;
                        }
                    }
                }
            }
            adj[j][i] = (((i + j) % 2 == 0) ? 1 : -1) * determinant(temp, size - 1);
        }
    }

    int det = determinant(matrix, size);
    if (det == 0)
    {
        printf("The matrix is singular, and its inverse does not exist.\n");
        return 1;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                inv[i][j] = (double)adj[i][j] / det;
            }
        }
    }
}

void matAdd()
{
    double m, n;

    printf("Enter number of rows: ");
    inputValid(&m);
    while (1)
    {
        if (m < 0 || m != (int)m)
        {
            printf("ERROR! Number of rows must be a valid positive integer.\nPlease try again: ");
            inputValid(&m);
        }
        else
        {
            break;
        }
    }

    printf("Enter number of columns: ");
    inputValid(&n);
    while (1)
    {
        if (n < 0 || n != (int)n)
        {
            printf("ERROR! Number of columns must be a valid positive integer.\nPlease try again: ");
            inputValid(&n);
        }
        else
        {
            break;
        }
    }

    int row = (int)m, col = (int)n;
    double mat1[row][col], mat2[row][col];

    printf("Enter the values for matrix 1: ");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            inputValid(&mat1[i][j]);
        }
    }

    printf("Enter the values for matrix 2: ");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            inputValid(&mat2[i][j]);
        }
    }

    printf("Sum of the 2 matrices:\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if ((mat1[i][j] + mat2[i][j]) != (int)(mat1[i][j] + mat2[i][j]))
            {
                printf("%.2lf ", mat1[i][j] + mat2[i][j]);
            }
            else
            {
                printf("%2d ", (int)(mat1[i][j] + mat2[i][j]));
            }
        }
        printf("\n");
    }

    userRepeat();
}
void matDiff()
{
    double m, n;

    printf("Enter number of rows: ");
    inputValid(&m);
    while (1)
    {
        if (m < 0 || m != (int)m)
        {
            printf("ERROR! Number of rows must be a valid positive integer.\nPlease try again: ");
            inputValid(&m);
        }
        else
        {
            break;
        }
    }

    printf("Enter number of columns: ");
    inputValid(&n);
    while (1)
    {
        if (n < 0 || n != (int)n)
        {
            printf("ERROR! Number of columns must be a valid positive integer.\nPlease try again: ");
            inputValid(&n);
        }
        else
        {
            break;
        }
    }

    int row = (int)m, col = (int)n;
    double mat1[row][col], mat2[row][col];

    printf("Enter the values for matrix 1: ");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            inputValid(&mat1[i][j]);
        }
    }

    printf("Enter the values for matrix 2: ");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            inputValid(&mat2[i][j]);
        }
    }

    printf("Difference of the 2 matrices:\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if ((mat1[i][j] - mat2[i][j]) != (int)(mat1[i][j] - mat2[i][j]))
            {
                printf("%.2lf ", mat1[i][j] - mat2[i][j]);
            }
            else
            {
                printf("%2d ", (int)(mat1[i][j] - mat2[i][j]));
            }
        }
        printf("\n");
    }

    userRepeat();
}
void matMul()
{
    double m1, n1, m2, n2;

    printf("Matrix 1:\n");
    printf("Enter number of rows: ");
    inputValid(&m1);
    while (1)
    {
        if (m1 < 0 || m1 != (int)m1)
        {
            printf("ERROR! Number of rows must be a valid positive integer.\nPlease try again: ");
            inputValid(&m1);
        }
        else
        {
            break;
        }
    }

    printf("Enter number of columns: ");
    inputValid(&n1);
    while (1)
    {
        if (n1 < 0 || n1 != (int)n1)
        {
            printf("ERROR! Number of columns must be a valid positive integer.\nPlease try again: ");
            inputValid(&n1);
        }
        else
        {
            break;
        }
    }

    int row1 = (int)m1, col1 = (int)n1;
    double mat1[row1][col1];

    printf("Enter the values for matrix 1: ");
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            inputValid(&mat1[i][j]);
        }
    }

    printf("Matrix 2:\n");
    printf("Enter number of rows: ");
    inputValid(&m2);
    while (1)
    {
        if (m2 < 0 || m2 != (int)m2)
        {
            printf("ERROR! Number of rows must be a valid positive integer.\nPlease try again: ");
            inputValid(&m2);
        }
        else if (m2 > 0 && m2 == (int)m2)
        {
            break;
        }
    }

    int row2 = (int)m2;

    if (row2 != col1)
    {
        while (1)
        {
            printf("ERROR! COLUMN NUMBER OF 1st MATRIX AND ROW NUMBER OF 2nd MATRIX MUST BE SAME!\n");
            printf("Enter number of rows of 2nd matrix: ");
            inputValid(&m2);
            while (1)
            {
                if (m2 < 0 || m2 != (int)m2)
                {
                    printf("ERROR! Number of rows must be a valid positive integer.\nPlease try again: ");
                    inputValid(&m2);
                }
                else if (m2 > 0 && m2 == (int)m2)
                {
                    break;
                }
            }
            row2 = (int)m2;
            if (row2 == col1)
            {
                break;
            }
        }
    }

    printf("Enter number of columns: ");
    inputValid(&n2);
    while (1)
    {
        if (n2 < 0 || n2 != (int)n2)
        {
            printf("ERROR! Number of columns must be a valid positive integer.\nPlease try again: ");
            inputValid(&n2);
        }
        else
        {
            break;
        }
    }

    int col2 = (int)n2;
    double mat2[row2][col2];

    printf("Enter the elements one by one: ");
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            inputValid(&mat2[i][j]);
        }
    }

    double prod[row1][col2];

    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            prod[i][j] = 0;
        }
    }

    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            for (int k = 0; k < col1; k++)
            {
                prod[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    printf("Product: \n");
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            if (prod[i][j] != (int)prod[i][j])
            {
                printf("%6.2lf ", prod[i][j]);
            }
            else
            {
                printf("%4d ", (int)prod[i][j]);
            }
        }
        printf("\n");
    }

    userRepeat();
}
void matTrans()
{
    double m, n;

    printf("Enter number of rows: ");
    inputValid(&m);
    while (1)
    {
        if (m < 0 || m != (int)m)
        {
            printf("ERROR! Number of rows must be a valid positive integer.\nPlease try again: ");
            inputValid(&m);
        }
        else
        {
            break;
        }
    }

    printf("Enter number of columns: ");
    inputValid(&n);
    while (1)
    {
        if (n < 0 || n != (int)n)
        {
            printf("ERROR! Number of columns must be a valid positive integer.\nPlease try again: ");
            inputValid(&n);
        }
        else
        {
            break;
        }
    }

    int row = (int)m, col = (int)n;
    double mat[row][col];

    printf("Enter the values for matrix: ");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            inputValid(&mat[i][j]);
        }
    }

    printf("Original: \n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (mat[i][j] == (int)mat[i][j])
            {
                printf("%2d ", (int)mat[i][j]);
            }
            else
            {
                printf("%6.2lf ", mat[i][j]);
            }
        }
        printf("\n");
    }

    printf("Transpose: \n");
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            if (mat[j][i] == (int)mat[j][i])
            {
                printf("%2d ", (int)mat[j][i]);
            }
            else
            {
                printf("%6.2lf ", mat[j][i]);
            }
        }
        printf("\n");
    }

    userRepeat();
}
void matDet()
{
    int matrix[MAX_SIZE][MAX_SIZE];
    double order;

    printf("Inverse possible only for a Square Matrix. Not a Rectangular Matrix.\n");
    printf("Enter the order of the matrix: ");
    inputValid(&order);
    while (1)
    {
        if (order < 0 || order != (int)order)
        {
            printf("ERROR! Order of matrix must be a valid positive integer.\nPlease try again: ");
            inputValid(&order);
        }
        else
        {
            break;
        }
    }

    int size = (int)order;

    printf("Enter the elements of the %dx%d matrix:\n", size, size);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    int det = determinant(matrix, size);
    if (det == (int)det)
    {
        printf("Determinant of the matrix is: %d\n", det);
    }
    else
    {
        printf("Determinant of the matrix is: %.2lf\n", det);
    }

    userRepeat();
}
void matInv()
{
    int matrix[MAX_SIZE][MAX_SIZE];
    double order;

    printf("Enter the order of the matrix: ");
    inputValid(&order);
    while (1)
    {
        if (order < 0 || order != (int)order)
        {
            printf("ERROR! Order of matrix must be a valid positive integer.\nPlease try again: ");
            inputValid(&order);
        }
        else
        {
            break;
        }
    }

    int size = (int)order;

    printf("Enter the elements of the %dx%d matrix:\n", size, size);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    double inv[MAX_SIZE][MAX_SIZE];

    if (inverse(matrix, size, inv) != 1)
    {
        printf("Inverse of the matrix:\n");
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (inv[i][j] != (int)inv[i][j])
                {
                    printf("%6.2lf ", inv[i][j]);
                }
                else
                {
                    printf("%4d ", (int)inv[i][j]);
                }
            }
            printf("\n");
        }
    }

    userRepeat();
}

int main()
{
    printf("\033c");

    double a;

    printf("\n===================== Matrix  Solver =====================\n\nMenu:\n1. Matrix Addition\n2. Matrix Subtraction\n3. Matrix Multiplication\n4. Transpose of Matrix\n5. Determinant of Matrix\n6. Inverse of Matrix\n7. Exit\n\nWhich type of calculation do you want to perform?\n");

    while (1)
    {
        printf("Enter a number between 1 to 7: ");
        if (scanf("%lf", &a) == 1 && a >= 1 && a <= 7)
        {
            if (a != (int)a)
            {
                printf("ERROR! Wrong Choice!\n");
                // Clear the input buffer
                while (getchar() != '\n')
                    ;
            }
            else
            {
                userInput = (int)a;
                break;
            }
        }
        else
        {
            printf("ERROR! Wrong Choice!\n");
            // Clear the input buffer
            while (getchar() != '\n')
                ;
        }
    }

    switch (userInput)
    {
    case 1:
        matAdd();
        break;
    case 2:
        matDiff();
        break;
    case 3:
        matMul();
        break;
    case 4:
        matTrans();
        break;
    case 5:
        matDet();
        break;
    case 6:
        matInv();
        break;
    case 7:
        printf("Ok... Exiting the calculator...\n");
        return 0;
        break;
    default:
        printf("INVALID RESPONSE! Try again.");
        break;
    }
    return 0;
}

void userRepeat() // Check if user wants to continue the same action. If yes, calls the same function again, else, return to main menu.
{
    char repeat[10];

    // Check if user wants to repeat this action or not.
    printf("Do you want to repeat this action?(Yes/No) ");
    scanf("%s", &repeat);

    // Convert the input to lowercase for case-insensitive comparison
    for (int i = 0; repeat[i]; i++)
    {
        repeat[i] = tolower(repeat[i]);
    }

    // Check if the input is "yes"
    while (1)
    {
        if ((strcmp(repeat, "yes") != 0 && strcmp(repeat, "y") != 0) && (strcmp(repeat, "no") != 0 && strcmp(repeat, "n") != 0))
        {
            printf("INVALID RESPONSE! Try Again! ");
            scanf("%s", &repeat);
            for (int i = 0; repeat[i]; i++)
            {
                repeat[i] = tolower(repeat[i]);
            }
        }
        else
        {
            break;
        }
    }

    if ((strcmp(repeat, "yes") == 0) || (strcmp(repeat, "y") == 0))
    {
        printf("\n");

        switch (userInput)
        {
        case 1:
            matAdd();
            break;
        case 2:
            matDiff();
            break;
        case 3:
            matMul();
            break;
        case 4:
            matTrans();
            break;
        case 5:
            matDet();
            break;
        case 6:
            matInv();
            break;
        default:
            break;
        }
    }
    else if ((strcmp(repeat, "no") == 0) || (strcmp(repeat, "n") == 0))
    {
        printf("Returning to main menu...\n");
        main();
    }
}
