#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Epanq Function
int epanq(int x, int y)
{
    return 2 * x + y;
}

// Opanq Function
int opanq(int x, int y)
{
    return 3 * y + x;
}

// Jhopanq Function
int jhopanq(int n1, int n2)
{
    int n1Last = n1 % 10;
    int n2Last = n2 % 10;

    return n1Last * 10 + n2Last;
}

// Ghochanq Function
int ghochanq(int (*ptr1)(int, int), int (*ptr2)(int, int), int (*ptr3)(int, int), int num1, int num2)
{
    int result1, result2, result3, ch;

    printf("Given two integers x = %d and y = %d, solve the following tasks to confirm your identity\n", num1, num2);
    printf("\n");

    // TASK 1 - epanq
    printf("TASK 1\n");
    printf("Calculate 2x + y: ");
    scanf("%d", &result1);
    while ((ch = getchar()) != '\n' && ch != EOF);

    if (result1 == ptr1(num1, num2))
    {
        printf("CORRECT\n");
    }
    else
    {
        return 0;
    }
    printf("\n");

    // TASK 2 - opanq
    printf("TASK 2\n");
    printf("Calculate x + 3y: ");
    scanf("%d", &result2);
    while ((ch = getchar()) != '\n' && ch != EOF);

    if (result2 == ptr2(num1, num2))
    {
        printf("CORRECT\n");
    }
    else
    {
        return 0;
    }

    // TASK 3 - jhopanq
    printf("TASK 3\n");
    printf("What are the last digits of the above answers in sequential order: ");
    scanf("%d", &result3);
    while ((ch = getchar()) != '\n' && ch != EOF);

    if (result3 == ptr3(result1, result2))
    {
        printf("CORRECT\n");
    }
    else
    {
        return 0;
    }
    printf("\n");

    // If all the tasks are performed correctly
    return 1;
}

void main()
{
    // Generating 2 random numbers 
    int max = 10, min = 5, num1, num2;
    srand(time(0)); // used to initialize or set the seed for the 'rand()' function, allowing us to generate different sequences of random numbers.

    num1 = rand() % (max - min + 1) + min; // rd_num is the random number between min and max
    num2 = rand() % (max - min + 1) + min;

    // Making function pointers 
    int (*ptr1)(int a, int b) = epanq;
    int (*ptr2)(int a, int b) = opanq;
    int (*ptr3)(int a, int b) = jhopanq;

    // Calling ghochanq with function pointers 
    int result = ghochanq(ptr1, ptr2, ptr3, num1, num2);
    printf("\n");

    if (result == 0)
    {
        printf("You are a TRESPASSER and will be met with serious consequences\n");
    }
    else
    {
        printf("Welcome to KHOPAT\n");
    }
}