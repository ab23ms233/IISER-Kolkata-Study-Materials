// QUESTION
// Write a program to find the maximum and the second maximum of three integers (taken as input from the terminal) using if-else.

#include <stdio.h>

void main()
{
    int num_1, num_2, num_3;
    int max, second_max;

    for (int i = 0; i < 6; i++)
    {
        printf("Enter number 1: ");
        scanf("%d", &num_1);
        printf("Enter number 2: ");
        scanf("%d", &num_2);
        printf("Enter number 3: ");
        scanf("%d", &num_3);

        if ((num_1 >= num_2) && (num_1 >= num_3))
        {
            max = num_1;

            if (num_2 >= num_3)     // num_1 >= num_2 >= num_3
            {
                second_max = num_2;
            }
            else                    // num_1 >= num_3 >= num_2
            {
                second_max = num_3;
            }
        }
        else if ((num_2 >= num_1) && (num_2 >= num_3))
        {
            max = num_2;

            if (num_1 >= num_3)     // num_2 >= num_1 >= num_3
            {
                second_max = num_1;
            }
            else                    // num_2 >= num_3 >= num_1
            {
                second_max = num_3;
            }
        }
        else
        {
            max = num_3;

            if (num_2 >= num_1)     // num_3 >= num_2 >= num_1
            {
                second_max = num_2;
            }
            else                    // num_3 >= num_1 >= num_2
            {
                second_max = num_1;
            }
        }

        printf("Maximum: %d\n", max);
        printf("Second maximum: %d\n", second_max);
        printf("\n");
    }
}
