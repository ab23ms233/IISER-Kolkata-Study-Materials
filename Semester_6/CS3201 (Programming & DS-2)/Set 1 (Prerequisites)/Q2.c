// QUESTION

// Consider a double type array (a) of five elements. Let p be a pointer pointing to array a. Using only p (without using a directly), find if a specific element E is present in array a; if yes, increment E in a by 1. Then, print the updated array using p. E.g., if a is {1.5, 2.4, 5.8, 11.35, 4.4} and E is 2.4, then the modified version of a (after the increment) will be {1.5, 3.4, 5.8, 11.35, 4.4}.


#include <stdio.h>

// Prints an array of a given size
void print_array(double array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%lf ", array[i]);
    }
    printf("\n"); 
}

void main()
{
    // User input of size of array
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    double element, a[size];

    // Taking user input for elements of the array
    for (int i = 0; i < size; i++)
    {
        printf("Enter element %d: ", i+1);
        scanf("%lf", &element);

        a[i] = element;
    }
    printf("\n");

    // Printing original array
    printf("Original Array: ");
    print_array(a, size);
    printf("\n");

    // Pointer to array
    double *p = a;
    double target;
    int found = 0;

    // User input for search element
    printf("Enter element to search: ");
    scanf("%lf", &target);

    // Checking for target using pointer
    for (int i = 0; i < size; i++)
    {
        if (*(p+i) == target)
        {
            // Incrementing value if target is found
            found = 1;
            (*(p+i))++;
        }
    }
    
    // Printing modified array if target is found
    if (found == 1)
    {
        printf("Modified Array: ");
        print_array(a, size);
    }
    else
    {
        printf("Element not found");
    }
}