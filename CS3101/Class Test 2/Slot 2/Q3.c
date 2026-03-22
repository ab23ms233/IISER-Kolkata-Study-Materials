#include <stdio.h>

// Function to check for spy number
int isSpy(int num)
{
    int sum = 0;        // Calculate sum of digits
    int product = 1;    // Calculate product of digits
    int remainder = 0;

    while (num)
    {
        remainder = num % 10;

        sum += remainder;
        product *= remainder;
        num = num / 10;
    }

    if (sum == product)
    {
        return 1;
    }

    return 0;
}

void main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    int result = isSpy(num);

    if (result == 1)
    {
        printf("%d is a spy number", num);
    }
    else
    {
        printf("%d is NOT a spy number", num);
    }
}