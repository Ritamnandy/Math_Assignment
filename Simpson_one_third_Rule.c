

// Simpson's 1/3 Rule

#include <stdio.h>
#include <math.h>

// Function to integrate
float f(float x)
{
    return 1 / (1 + x * x);
}

int main()
{
    int n, i;
    float a, b, h, sum, result;

    printf("Enter lower limit (a):- ");
    scanf("%f", &a);

    printf("Enter upper limit (b):- ");
    scanf("%f", &b);

    printf("Enter number of subintervals (even number):- ");
    scanf("%d", &n);

    if (n % 2 != 0)
    {
        printf("Error! Number of subintervals must be even.\n");
        return 0;
    }

    h = (b - a) / n;

    sum = f(a) + f(b);

    for (i = 1; i < n; i++)
    {
        if (i % 2 == 0)
            sum += 2 * f(a + i * h);
        else
            sum += 4 * f(a + i * h);
    }

    result = (h / 3) * sum;

    printf("\nApproximate value of the integral = %.6f\n", result);

    return 0;
}