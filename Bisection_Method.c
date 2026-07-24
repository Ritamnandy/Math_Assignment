
#include <stdio.h>
#include <math.h>

// Function definition
float f(float x)
{
    return x * x * x - x - 2;
}

int main()
{
    float a, b, c;
    float error;
    int iteration = 0;

    printf("Enter the value of a and b: ");
    scanf("%f %f", &a, &b);

    // Check if root exists
    if (f(a) * f(b) > 0)
    {
        printf("Invalid interval! Root does not lie between %.2f and %.2f\n", a, b);
        return 0;
    }

    printf("Enter the allowable error: ");
    scanf("%f", &error);

    printf("\nIteration\t a\t\t b\t\t c\t\t f(c)\n");

    do
    {
        c = (a + b) / 2;

        printf("%d\t\t %.6f\t %.6f\t %.6f\t %.6f\n", iteration + 1, a, b, c, f(c));

        if (f(c) == 0.0)
        {
            break;
        }
        else if (f(a) * f(c) < 0)
        {
            b = c;
        }
        else
        {
            a = c;
        }

        iteration++;

    } while (fabs(f(c)) > error);

    printf("\nApproximate Root = %.6f\n", c);

    return 0;
}