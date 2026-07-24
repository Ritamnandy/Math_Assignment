
// Gauss Jacobi Method

#include <stdio.h>
#include <math.h>

int main()
{
    int i, j, n, iter, maxIter;
    float a[10][10], b[10], x[10], newX[10], error, tolerance;

    printf("Enter the number of variables:- ");
    scanf("%d", &n);

    printf("Enter the coefficients of the matrix:-\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%f", &a[i][j]);
        }
    }

    printf("Enter the constant terms:-\n");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &b[i]);
    }

    printf("Enter the initial guesses:-\n");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &x[i]);
    }

    printf("Enter the tolerance:- ");
    scanf("%f", &tolerance);

    printf("Enter the maximum number of iterations:- ");
    scanf("%d", &maxIter);

    printf("\nIteration\tValues of x\n");

    for (iter = 1; iter <= maxIter; iter++)
    {

        for (i = 0; i < n; i++)
        {
            float sum = 0;

            for (j = 0; j < n; j++)
            {
                if (i != j)
                    sum += a[i][j] * x[j];
            }

            newX[i] = (b[i] - sum) / a[i][i];
        }

        printf("%d\t\t", iter);
        for (i = 0; i < n; i++)
        {
            printf("%8.4f ", newX[i]);
        }
        printf("\n");

        error = 0;
        for (i = 0; i < n; i++)
        {
            if (fabs(newX[i] - x[i]) > error)
                error = fabs(newX[i] - x[i]);
        }

        if (error < tolerance)
        {
            printf("\nSolution converged.\n");
            break;
        }

        for (i = 0; i < n; i++)
        {
            x[i] = newX[i];
        }
    }

    printf("\nApproximate Solution:\n");
    for (i = 0; i < n; i++)
    {
        printf("x%d = %.6f\n", i + 1, newX[i]);
    }

    return 0;
}