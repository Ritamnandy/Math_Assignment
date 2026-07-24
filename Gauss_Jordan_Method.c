
// Gauss Jordan Method

#include <stdio.h>

int main()
{
    int i, j, k, n;
    float a[10][20], ratio;

    printf("Enter the order of the matrix:- ");
    scanf("%d", &n);

    printf("Enter the elements of the matrix:-\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%f", &a[i][j]);
        }
    }

    // Create the augmented matrix [A | I]
    for (i = 0; i < n; i++)
    {
        for (j = n; j < 2 * n; j++)
        {
            if (j == i + n)
                a[i][j] = 1;
            else
                a[i][j] = 0;
        }
    }

    // Gauss-Jordan Elimination
    for (i = 0; i < n; i++)
    {
        if (a[i][i] == 0.0)
        {
            printf("\nMatrix is singular! Inverse does not exist.\n");
            return 0;
        }

        // Make the pivot element 1
        ratio = a[i][i];
        for (j = 0; j < 2 * n; j++)
        {
            a[i][j] = a[i][j] / ratio;
        }

        // Make all other elements in the pivot column 0
        for (k = 0; k < n; k++)
        {
            if (k != i)
            {
                ratio = a[k][i];
                for (j = 0; j < 2 * n; j++)
                {
                    a[k][j] = a[k][j] - ratio * a[i][j];
                }
            }
        }
    }

    // Display inverse matrix
    printf("\nInverse Matrix is:\n");
    for (i = 0; i < n; i++)
    {
        for (j = n; j < 2 * n; j++)
        {
            printf("%8.3f ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}