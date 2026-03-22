// QUESTION 1

// Implement a function MAXINT2() that takes two integers as arguments and returns the maximum of them. Take two integers as input, and using MAXINT2(), print the maximum. Similarly, implement MININT2() and print the minimum of the same integers.

// QUESTION 2

// Take three integers as input and, using MAXINT2() print the maximum of these three integers. Using MININT2(), similarly, print the minimum of the same integers.

#include <stdio.h>

// Function for finding maximum of 2 integers
int MAXINT2(int num_1, int num_2)
{
    if (num_1 >= num_2)
    {
        return num_1;
    }
    else
    {
        return num_2;
    }
}

// Function for finding minimum of 2 integers
int MININT2(int num_1, int num_2)
{
    if (num_1 >= num_2)
    {
        return num_2;
    }
    else
    {
        return num_1;
    }
}

void main()
{
    // Q1
    // int num_1, num_2;

    // printf("Enter number 1: ");
    // scanf("%d", &num_1);
    // printf("Enter number 2: ");
    // scanf("%d", &num_2);

    // int max = MAXINT2(num_1, num_2);
    // int min = MININT2(num_1, num_2);

    // printf("Maximum: %d\n", max);
    // printf("Minimum: %d\n", min);

    // Q2
    int num_1, num_2, num_3;

    printf("Enter number 1: ");
    scanf("%d", &num_1);
    printf("Enter number 2: ");
    scanf("%d", &num_2);
    printf("Enter number 3: ");
    scanf("%d", &num_3);

    int max_12 = MAXINT2(num_1, num_2);
    int max = MAXINT2(max_12, num_3);
    int min_12 = MININT2(num_1, num_2);
    int min = MININT2(min_12, num_3);

    printf("Maximum: %d\n", max);
    printf("Minimum: %d\n", min);
}