// QUESTION

//  Write a C program to generate a pattern for any value of n ≥ 1 as shown in Figure 1 (for n = 8). The value of n should be taken as input from the terminal.

// *
// *
// **
// ***
// *****
// ********
// *************
// *********************


#include <stdio.h>

void main()
{
    int rows;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    int t0 = 0;
    int t1 = 1;
    int next_term;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < t1; j++)
        {
            printf("*");
        }
        printf("\n");

        next_term = t0 + t1;
        t0 = t1;
        t1 = next_term;
    }
}