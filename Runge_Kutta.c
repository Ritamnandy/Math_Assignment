
#include <stdio.h>

// Function representing dy/dx = f(x, y)
float f(float x, float y)
{
    return x + y; // Example: dy/dx = x + y
}

int main()
{
    float x0, y0, x, h;
    int n, i;
    float k1, k2, k3, k4;

    printf("Enter initial value of x (x0): ");
    scanf("%f", &x0);

    printf("Enter initial value of y (y0): ");
    scanf("%f", &y0);

    printf("Enter step size (h): ");
    scanf("%f", &h);

    printf("Enter final value of x: ");
    scanf("%f", &x);

    n = (x - x0) / h;

    printf("\n---------------------------------------\n");
    printf("Step\t x\t\t y\n");
    printf("---------------------------------------\n");

    for (i = 1; i <= n; i++)
    {
        k1 = h * f(x0, y0);
        k2 = h * f(x0 + h / 2, y0 + k1 / 2);
        k3 = h * f(x0 + h / 2, y0 + k2 / 2);
        k4 = h * f(x0 + h, y0 + k3);

        y0 = y0 + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        x0 = x0 + h;

        printf("%d\t %.2f\t\t %.6f\n", i, x0, y0);
    }

    printf("---------------------------------------\n");
    printf("\nApproximate value of y at x = %.2f is %.6f\n", x0, y0);

    return 0;
}