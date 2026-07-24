// Newton Raphson Method
// Equation: x^3 - 8x - 4 = 0
// input 3,0.0001
#include <stdio.h>
#include <math.h>

// Function
float function(float x)
{
    return x * x * x - 8 * x - 4;
}

// Derivative of the function
float derivative(float x)
{
    return 3 * x * x - 8;
}

int main()
{
    float x, h, tolerance;
    int i = 1;

    printf("Enter the initial approximation:- ");
    scanf("%f", &x);

    printf("Enter the tolerance:- ");
    scanf("%f", &tolerance);

    do
    {
        // Check if derivative is zero
        if (fabs(derivative(x)) < 1e-10)
        {
            printf("Derivative is zero. Method cannot continue.\n");
            return 0;
        }

        h = function(x) / derivative(x);

        x = x - h;

        printf("Iteration %d : x = %.6f\n", i, x);

        i++;
    } while (fabs(h) > tolerance);

    printf("\nRoot = %.6f\n", x);

    return 0;
}