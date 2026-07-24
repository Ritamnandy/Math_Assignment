// Newton Backward Interpolation

#include <stdio.h>
#include <math.h>

#define SIZE 100

int fact(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * fact(n - 1);
}
float cal_u(int n, float u)
{
    float sum = u;
    for (int i = 1; i < n; i++)
    {
        sum *= (u + i);
    }
    return sum;
}

int main()
{
    float x[SIZE], y[SIZE][SIZE], u, input, result;
    int i, j, n;
    printf("Enter the number of data points:- ");
    scanf("%d", &n);
    printf("Enter the values of x:- \n");
    for (i = 0; i < n; i++)
    {
        printf("x[%d] = ", i + 1);
        scanf("%f", &x[i]);
    }
    printf("Enter the corresponding values of y:- \n");
    for (i = 0; i < n; i++)
    {
        printf("y[%d] = ", i + 1);
        scanf("%f", &y[i][0]);
    }
    /* forward difference table  calculations*/
    for (i = 1; i < n; i++)
    {
        for (j = n - 1; j >= i; j--)
        {
            y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
        }
    }
    printf("Displaying the backward difference table:-\n");

    for (i = 0; i < n; i++)
    {
        printf("%.3f\t", x[i]);
        for (j = 0; j <= n - i; j++)
        {
            printf("%.3f\t", y[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter the value of x to be interpolated:- ");
    scanf("%f", &input);
    u = (input - x[n - 1]) / (x[1] - x[0]);

    result = y[n - 1][0];

    for (i = 1; i < n; i++)
    {
        result += (cal_u(i, u) * y[n - 1][i]) / fact(i);
    }
    printf("\nInterpolated value at x = %f is %f\n", input, result);

    return 0;
}