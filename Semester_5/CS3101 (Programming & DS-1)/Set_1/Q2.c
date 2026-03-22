// QUESTION
// Write a program in C	programming language to take a number as input from the user and print its square on the terminal.

# include <stdio.h>

void main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("The square of %d is %d", num, num*num);
}
