// Gauss Seidel Method

#include <stdio.h>
#include <math.h>

int main()
{
    int n, i, j, k, maxIter;
    float a[10][10], x[10], newX, error, tolerance;

    printf("Enter the number of variables:- ");
    scanf("%d", &n);

    printf("Enter the augmented matrix coefficients:-\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            scanf("%f", &a[i][j]);
        }
    }

    printf("Enter initial guesses:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &x[i]);
    }

    printf("Enter tolerance:- ");
    scanf("%f", &tolerance);

    printf("Enter maximum number of iterations:- ");
    scanf("%d", &maxIter);

    printf("\nIterations:\n");

    for (k = 1; k <= maxIter; k++)
    {
        error = 0;

        for (i = 0; i < n; i++)
        {
            newX = a[i][n];

            for (j = 0; j < n; j++)
            {
                if (j != i)
                    newX = newX - a[i][j] * x[j];
            }

            newX = newX / a[i][i];

            if (fabs(newX - x[i]) > error)
                error = fabs(newX - x[i]);

            x[i] = newX;
        }

        printf("Iteration %d:- ", k);
        for (i = 0; i < n; i++)
        {
            printf("x%d = %.6f ", i + 1, x[i]);
        }
        printf("\n");

        if (error < tolerance)
            break;
    }

    printf("\nApproximate Solution:-\n");
    for (i = 0; i < n; i++)
    {
        printf("x%d = %.6f\n", i + 1, x[i]);
    }

    return 0;
}