
// Lagrange Interpolation
// input x=1,2,4,y=2,3,7, xS=3

#include <stdio.h>

int main()
{
    int n, i, j;
    float x[20], y[20], xp, yp = 0, p;

    printf("Enter the number of data points:- ");
    scanf("%d", &n);

    printf("\nEnter the values of x:-\n");

    for (i = 0; i < n; i++)
    {
        printf("x[%d] = ", i + 1);
        scanf("%f", &x[i]);
    }
    printf("\nEnter the values of y:-\n");
    for (i = 0; i < n; i++)
    {
        printf("y[%d] = ", i + 1);
        scanf("%f", &y[i]);
    }

    printf("\nEnter the value of x where you want to interpolate: ");
    scanf("%f", &xp);

    // Lagrange Interpolation
    for (i = 0; i < n; i++)
    {
        p = 1;

        for (j = 0; j < n; j++)
        {
            if (i != j)
            {
                p = p * (xp - x[j]) / (x[i] - x[j]);
            }
        }

        yp = yp + p * y[i];
    }

    printf("\nInterpolated value at x = %.2f is %.4f\n", xp, yp);

    return 0;
}