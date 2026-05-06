// QUESTION
// Write a program in C	programming language to take as input the base (b) and height (h) of a triangle and print the area on the terminal (formula: area = (½)*base*height).

# include <stdio.h>

void main() {
    float height, base;
    printf("Enter height: ");
    scanf("%f", &height);

    printf("Enter base: ");
    scanf("%f", &base);

    float area = 0.5 * base * height;

    printf("Area: %f", area);
}