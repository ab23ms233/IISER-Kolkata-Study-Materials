// QUESTION

// Consider an integer array A of integers and a function AVGINTARRAY() that takes A (with the number of elements in it) as arguments, returning the average of the elements in A. Note that although the elements in A are integers, their average can be a real number; so please define AVGINTARRAY() accordingly.

#include <stdio.h>

// Function to find average of integer array
float AVGINTARRAY(const int array[], int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }

    return (float)sum / size;
}

// Function to print an array
void print_array(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void main()
{
    // Taking array as user input
    const int size = 5;
    int numbers[size];
    int element;

    for (int i = 0; i < size; i++)
    {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &element);

        numbers[i] = element;
    }

    printf("Original Array: ");
    print_array(numbers, size);

    float average = AVGINTARRAY(numbers, size);
    printf("Average: %f\n", average);
}
