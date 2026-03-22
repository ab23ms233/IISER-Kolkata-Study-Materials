// QUESTION
// Write a program to print the floor and ceil of a real number without using ceil() and floor() functions of math.h (or any other in-built functions). E.g., for a number n = 55.5, floor(n) = 55.0 (i.e., the immediately previous integer) and ceil(n) = 56.0 i.e., the immediately next integer). There is no need to take user input.

// We are taking user input in this case for general purpose use

#include <stdio.h>

void main() {
    float num;
    int floor, ceil;

    printf("Enter the number: ");
    scanf("%f", &num);

    floor = (int) num;
    if (floor == num)
    {
        ceil = num;
    }
    else
    {
        ceil = floor + 1;
    }
    
    printf("Floor of %f: %d\n", num, floor);
    printf("Ceil of %f: %d\n", num, ceil);
}
