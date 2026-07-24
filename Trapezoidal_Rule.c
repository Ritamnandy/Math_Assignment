
// Trapezoidal Rule

#include <stdio.h>
#include <math.h>

// Define the function f(x)
float f(float x)
{
    return x * x; // Example: f(x) = x²
}

int main()
{
    int n, i;
    float a, b, h, sum, integral;

    printf("Enter lower limit (a):- ");
    scanf("%f", &a);

    printf("Enter upper limit (b):- ");
    scanf("%f", &b);

    printf("Enter number of sub-intervals (n):- ");
    scanf("%d", &n);

    h = (b - a) / n;

    sum = f(a) + f(b);

    for (i = 1; i < n; i++)
    {
        sum = sum + 2 * f(a + i * h);
    }

    integral = (h / 2) * sum;

    printf("\nApproximate value of the integral = %.6f\n", integral);

    return 0;
}