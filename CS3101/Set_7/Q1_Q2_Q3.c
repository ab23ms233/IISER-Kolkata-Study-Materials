// QUESTION 1
// Take a number n as input. Write a recursive function that prints the numbers 1-n in reverse order.

// QUESTION 2
// Take a number n as input. Write a recursive function that prints the numbers 1-n in forward order.

// QUESTION 3
// Take a number n as input. Write a recursive function that prints the sum of numbers 1-n.

#include <stdio.h>

// Function for reverse display of integers
void display_reverse(int n)
{
    if (n == 0)
    {
        return;
    }

    printf("%d\n", n);
    display_reverse(n - 1);
}

// Function for forward display of integers
void display_forward(int n)
{
    if (n == 0)
    {
        return;
    }

    display_forward(n - 1);
    printf("%d\n", n);
}

// Function to find sum of integers
int recursive_sum(int n)
{
    if (n == 1)
    {
        return 1;
    }

    return n + recursive_sum(n - 1);
}

int sum_of_divisors(int n)
{
    static int x = 0;
    x++;

    if (x == n/2)
    {
        if (n % x == 0)
        {
            printf("x = n/2 and n/x = 0: %d\n", x);
            return x;
        }
        else
        {
            return 0;
        }
    }

    if (n % x == 0)
    {
        printf("n/x = 0: %d\n", x);
        return x + sum_of_divisors(n);
    }
    else
    {
        printf("n/x != 0: %d\n", x);
        return sum_of_divisors(n);
    }
}


void main()
{
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Forward display:\n");
    display_forward(n);
    printf("\n");

    printf("Reverse display:\n");
    display_reverse(n);
    printf("\n");

    int sum = recursive_sum(n);
    printf("Sum: %d\n", sum);
    printf("\n");
}