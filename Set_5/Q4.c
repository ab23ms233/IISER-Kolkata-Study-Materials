// QUESTION

// Consider an integer array named marks containing the marks (out of 100) of five students. Define a function grace_marks(), which takes an array of integers, along with the number of elements in the array, as arguments, and adds grace marks of 5 to those students who obtained less than 40. Print the values of the array marks before and after passing the array to grace_marks().

#include <stdio.h>

// Function for giving grace marks
void grace_marks(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] < 40)
        {
            array[i] += 5;
        }
    }
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
    int size = 5;
    int marks[size];
    int element;

    for (int i = 0; i < size; i++)
    {
        printf("Enter marks %d: ", i + 1);
        scanf("%d", &element);

        marks[i] = element;
    }

    printf("\n");
    printf("Original Array: ");
    print_array(marks, size);

    grace_marks(marks, size);
    printf("Updated Array: ");
    print_array(marks, size);
}