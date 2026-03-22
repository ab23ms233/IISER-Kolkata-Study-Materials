// QUESTION
// Write a program in C	programming language to take as input two numbers and swap them using a third variable.

# include <stdio.h>

void main(){
    int num_1, num_2, temp;  // temp = temporary variable for swapping
    printf("Enter 1st number: ");
    scanf("%d", &num_1);

    printf("Enter 2nd number: ");
    scanf("%d", &num_2);

    temp = num_1;
    num_1 = num_2;
    num_2 = temp;

    printf("Number 1: %d\n", num_1);
    printf("Number 2: %d\n", num_2);
}