#include <stdio.h>

void printHalfRev(int num)
{
    if (num == 1)
    {
        printf("0.5\n");
        return;
    }

    printf("%f\n", (float) num/2);
    printHalfRev(num - 1);
}

void main() {
    int num;
    printf("Enter the number of terms: ");
    scanf("%d", &num);

    if (num < 1)
    {
        printf("Number of terms should be a natural number");
    }
    else
    {
        printHalfRev(num);
    }
}