// QUESTION

// Assume that sin(x) can be expressed as the sum of the series: x - x3/3! + x5/5!....... ; for any x in radians. Implement a function Sin(x, n) in C, where n is the number of terms to be considered in the sum. In addition, implement a factorial function. You can use the pow() function in math.h and sin(x) in the same header file to compare the computed value by Sin().

#include <stdio.h>
#include <math.h>

// Function to calculate factorial of an integer
int factorial(int num)
{
    if (num == 0 || num == 1)
    {
        return 1;
    }
    else
    {
        return num * factorial(num - 1);
    }
}

// Function to calculate value of sin(x) from series expansion upto n terms
float Sin(float x, int n)
{
    float sum = 0;
    int denominator, power;
    int sign = 1;
    float term, numerator;

    for (int i = 0; i < n; i++)
    {
        power = 2 * i + 1;
        denominator = factorial(power);
        numerator = (float) pow(x, power);
        term = (float) sign * numerator / denominator;

        sum += term;
        sign *= -1;
    }

    return sum;
}


void main()
{
    int n;
    float x, calculated, actual;

    printf("Enter x (in radians): ");
    scanf("%f", &x);
    printf("Enter number of terms required in the expansion: ");
    scanf("%d", &n);
    printf("\n");

    calculated = Sin(x, n);
    actual = sin(x);

    printf("Calculated value for x = %0.3f: %f\n", x, calculated);
    printf("Actual value for x = %0.3f: %f\n", x, actual);
    printf("Difference: %0.3f", fabs(actual - calculated));
}
