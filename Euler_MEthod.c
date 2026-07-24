
// Euler Method

#include <stdio.h>

// Function representing dy/dx = f(x, y)
float f(float x, float y)
{
    return x + y; // Example: f(x, y) = x + y
}

int main()
{
    float x0, y0, h, xn, y;

    printf("Enter initial value of x (x0):- ");
    scanf("%f", &x0);

    printf("Enter initial value of y (y0):- ");
    scanf("%f", &y0);

    printf("Enter step size (h):- ");
    scanf("%f", &h);

    printf("Enter final value of x (xn):- ");
    scanf("%f", &xn);

    y = y0;

    while (x0 < xn)
    {
        y = y + h * f(x0, y);
        x0 = x0 + h;

        printf("x = %.2f\t y = %.4f\n", x0, y);
    }

    printf("\nApproximate value of y at x = %.2f is %.4f\n", xn, y);

    return 0;
}