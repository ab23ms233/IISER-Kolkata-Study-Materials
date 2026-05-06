// QUESTION
// Write a program to print the absolute value of an integer (I), which is the negation of the integer I if I is negative, else it is the same as I. Apply both if-else and the conditional operator (?:). There is no need to take user input

// We are taking user input in this case for general purpose use

#include <stdio.h>

void main() {
    int num, result;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num >= 0) 
    {
        result = num;
    } 
    else 
    {
        result = -num;
    }

    printf("Absolute value of %d is %d", num, result);
}
