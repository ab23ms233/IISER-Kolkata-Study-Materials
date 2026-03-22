// QUESTION

// Take a number n as input. Write a recursive function that prints if n is a perfect number or not.

#include <stdio.h>

// Function to find sum of divisors
int sum_of_divisors(int n, int x)
{
    // Base Case
    if (x == 0 || x == 1)
    {
        return 1;
    }

    if (n % x == 0)
    {
        return x + sum_of_divisors(n, x - 1);
    }
    else
    {
        return sum_of_divisors(n, x - 1);
    }
}

void main()
{
    int max, sum;
    printf("Enter max number upto which you want to find perfect numbers: ");
    scanf("%d", &max);  
    printf("\n");

    printf("Perfect numbers: \n");

    // Find perfect numbers from 1 - max
    for (int i = 1; i <= max; i++)
    {
        sum = sum_of_divisors(i, i/2);

        if (sum == i)
        {
            printf("%d\n", i);
        }
    }  
}