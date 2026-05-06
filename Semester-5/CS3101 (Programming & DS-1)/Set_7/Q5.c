// QUESTION

// Print the patterns using a recursive function for any n (to be passed to the function):

// (a) For n = 4
		
// 1 
// 1 2 
// 1 2 3 
// 1 2 3 4

// (b) For n = 4

// 1 2 3 4 
// 1 2 3 
// 1 2 
// 1 

#include <stdio.h>

// Function to print integers in forward direction (Part a)
void print_forward(int n) {
    if (n == 0) {
        return;
    }

    print_forward(n-1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", i+1);
    }

    printf("\n"); 
}

// Function to print integers in reverse direction (Part b)
void print_reverse(int n) {
    if (n == 0) {
        return;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", i+1);
    }
    printf("\n");

    print_reverse(n-1);
}


void main() {
    int num;
    printf("Enter number of rows: ");
    scanf("%d", &num);
    printf("\n");

    printf("Forward printing\n");
    print_forward(num);
    printf("\n");

    printf("Reverse printing\n");
    print_reverse(num);
}