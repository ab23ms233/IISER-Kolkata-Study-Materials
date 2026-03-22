// QUESTION

// Consider an array A = [2, 4, 6, 8, 10, 12, 14, 0, 0, 0, 0], where 0s specify empty slots. Note that the non-zero subarray in the array is sorted. Insert a new element x (input from the user) in array A at the end (replacing the first 0) by searching for the first 0.  Now implement a search algorithm to search for any element in the array. Compute the time complexity (using Big O) and put it as a comment in your code.

#include <stdio.h>

void main()
{

    // Inserting element into the Array
    int A[] = {2, 4, 6, 8, 10, 12, 14, 0, 0, 0, 0};
    int size = sizeof(A) / sizeof(A[0]);

    int element;
    printf("Enter new element: ");
    scanf("%d", &element);

    for (int i = 0; i < size; i++)
    {
        // Update 1st 0 and break
        if (A[i] == 0)
        {
            A[i] = element;
            break;
        }
    }

    // Printing Updated Array
    printf("Updated array: ");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    // Searching for a particular element - Linear Search. Time Complexity - O(n)
    int search_element, flag = -1;
    printf("Enter search element: ");
    scanf("%d", &search_element);

    for (int i = 0; i < size; i++)
    {
        // If element is found, flag = 0
        if (A[i] == search_element)
        {
            printf("Element found at position %d\n", i + 1);
            flag = 0;
            break;
        }
    }
    // If element is not found
    if (flag == -1)
    {
        printf("Element not found\n");
    }
}