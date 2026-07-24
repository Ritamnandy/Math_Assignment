# Numerical Methods in C

This repository contains standalone C programs for common numerical methods used in computational mathematics. Each source file implements one method and reads input interactively from the terminal.

## Methods Included

| File | Method | Purpose |
| --- | --- | --- |
| `Bisection_Method.c` | Bisection Method | Finds an approximate root of `x^3 - x - 2 = 0` in a given interval. |
| `Newton_Raphson_Method.c` | Newton-Raphson Method | Finds an approximate root of `x^3 - 8x - 4 = 0` from an initial guess. |
| `Gauss_Elimination_Method.c` | Gauss Elimination | Solves a system of linear equations using forward elimination and back substitution. |
| `Gauss_Jordan_Method.c` | Gauss-Jordan Method | Finds the inverse of a square matrix. |
| `Gauss_Jacobi_Method.c` | Gauss-Jacobi Method | Solves a system of linear equations iteratively. |
| `Gauss_Seidel_Method.c` | Gauss-Seidel Method | Solves a system of linear equations iteratively using updated values immediately. |
| `Lagrange_Interpolation.c` | Lagrange Interpolation | Interpolates a value from given data points. |
| `newton_forward.c` | Newton Forward Interpolation | Interpolates values using a forward difference table. |
| `newton_backward_formula.c` | Newton Backward Interpolation | Interpolates values using a backward difference table. |
| `Euler_MEthod.c` | Euler Method | Solves an ordinary differential equation using Euler's method. |
| `Runge_Kutta.c` | Fourth-Order Runge-Kutta Method | Solves an ordinary differential equation using RK4. |
| `Trapezoidal_Rule.c` | Trapezoidal Rule | Approximates a definite integral. |
| `Simpson_one_third_Rule.c` | Simpson's 1/3 Rule | Approximates a definite integral using an even number of subintervals. |

## Requirements

- A C compiler such as `gcc`
- Standard C library
- Math library support for programs that include `math.h`

On Linux, install GCC with:

```bash
sudo apt install gcc
```

## Compile and Run

Compile any program with `gcc`. Some files use functions from `math.h`, so link the math library with `-lm`.

Example:

```bash
gcc Bisection_Method.c -o Bisection_Method -lm
./Bisection_Method
```

Another example:

```bash
gcc Gauss_Elimination_Method.c -o Gauss_Elimination_Method
./Gauss_Elimination_Method
```

To compile all `.c` files at once:

```bash
for file in *.c; do
  output="${file%.c}"
  gcc "$file" -o "$output" -lm
done
```

## Usage Notes

- Run each executable from the terminal and enter values when prompted.
- Root-finding and integration programs currently use hard-coded sample functions. To solve a different problem, edit the function definition in the corresponding `.c` file.
- Matrix programs accept values from standard input. Enter matrix coefficients row by row.
- Iterative methods such as Jacobi and Seidel require initial guesses, tolerance, and maximum iteration count.
- Simpson's 1/3 Rule requires an even number of subintervals.

## Example: Bisection Method

Compile:

```bash
gcc Bisection_Method.c -o Bisection_Method -lm
```

Run:

```bash
./Bisection_Method
```

Sample input:

```text
1 2
0.0001
```

The program prints each iteration and the final approximate root.

## Example: Gauss Elimination

Compile:

```bash
gcc Gauss_Elimination_Method.c -o Gauss_Elimination_Method
```

Run:

```bash
./Gauss_Elimination_Method
```

For `n` variables, enter an augmented matrix with `n` rows and `n + 1` values in each row.

Example input for a 3-variable system:

```text
3
1 1 1 6
2 5 5 -4
2 3 8 5
```

## Project Structure

```text
.
├── *.c        # Source code for each numerical method
├── README.md # Project documentation
└── binaries  # Compiled executables generated from the C files
```

## Notes for Contributors

- Keep each method in a separate source file.
- Use clear prompts for all required input values.
- Add comments for the formula or algorithm steps when helpful.
- Avoid committing generated executables if this repository is intended to store source code only.
