#include <stdio.h>
#include <stdlib.h>

// Maximum size of Stack is 100
#define MAX 100

int stack_arr[MAX];
int top = -1;      // Refers to the index of the topmost element

// Function to check if Stack is empty
// Returns 1 if empty
// Returns 0 if not
int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    
    return 0;
}

// Function to check if Stack is full
// Returns 1 if full
// Returns 0 if not
int isFull()
{
    if (top == MAX - 1)
    {
        return 1;
    }
    
    return 0;
}

// Function to add element to the top of the stack
void push(int item)
{
    if (isFull())
    {
        printf("Stack Overflow\n");
        return;
    }

    top += 1;
    stack_arr[top] = item;
}

// Function to remove element from the top of the stack
// Returns the element popped/removed
int pop()
{
    if (isEmpty())
    {
        printf("Stack Underflow\n");
        return -999;
    }

    int item = stack_arr[top];
    top -= 1;
    return item;
}

// Function to check the element at the top of the stack
// Returns the element at the top of the stack
int peek()
{
    if (isEmpty())
    {
        printf("Stack Underflow\n");
        return -999;
    }

    return stack_arr[top];
}

// Function to display all elements of a stack
void display()
{
    if (isEmpty())
    {
        printf("Stack Underflow\n");
        return;
    }

    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack_arr[i]);
    }
    printf("\n");
}