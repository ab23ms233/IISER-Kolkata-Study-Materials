#include <stdio.h>

// Maximum size of Queue is 100
#define MAX 100

int queue_arr[MAX];
int rear = -1;      // Refers to the index of the last/rear element
int front = -1;     // Refers to the index of the first/front element

// Function to check if Queue is empty
// Returns 1 if empty
// Returns 0 if not
int isFull()
{
    if (rear == MAX - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Function to check if Queue is full
// Returns 1 if full
// Returns 0 if not
int isEmpty()
{
    if (front == -1 || front == rear + 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Function to add element to the end/rear of the queue
void enqueue(int item)
{
    if (isFull())
    {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1)
    {
        front = 0;
    }

    rear += 1;
    queue_arr[rear] = item;
}

// Function to remove element from the front of the queue
// Returns the element popped/removed
int dequeue()
{
    if (isEmpty())
    {
        printf("Queue Underflow\n");
        return -999;
    }

    int item = queue_arr[front];
    front += 1;
    return item;
}

// Function to check the element at the front of the queue
// Returns the element at the top of the stack
int peek()
{
    if (isEmpty())
    {
        printf("Queue Underflow\n");
        return -999;
    }

    return queue_arr[front];
}

void main()
{
    push(2);
}
