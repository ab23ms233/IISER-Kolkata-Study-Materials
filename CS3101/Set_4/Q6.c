// QUESTION

// Improve the insertion method in Q5 by inserting at an appropriate location in the array such that the non-zero elements in it remain sorted. Now perform the search using a better search algorithm (better than O(n)) in terms of Big O.

#include <stdio.h>

// Function to find Non-Zero Elements of an array
int find_NonZero_Count(int array[], int size)
{
    int nonzero_count = 0;

    for (int i = 0; i < size; i++)
    {
        if (array[i] != 0)
        {
            nonzero_count++;
        }
    }

    return nonzero_count;
}

// Function to print elements of an Array
void print_array(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Function for Binary Search
int Binary_Search(int array[], int size, int search_element)
{
    // Conduct search only on non-zero elements
    int nonzero_count = find_NonZero_Count(array, size);
    int start = 0;
    int end = nonzero_count - 1;
    int mid = (end + start) / 2;
    
    while (start != end + 1)
    {
        if (search_element == array[mid])
        {
            return mid;
        }
        else if (search_element > array[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }

        mid = (start + end) / 2;
    }

    return -1; // If element is not found
}

void main()
{
    // Initialising Array
    int A[] = {2, 4, 6, 8, 10, 12, 14, 0, 0, 0, 0};
    int size = sizeof(A) / sizeof(A[0]);

    // Checking if Array is full
    int nonzero_count = find_NonZero_Count(A, size);

    if (nonzero_count == size) // If array is full
    {
        printf("Array is Full. Cannot insert new element");
    }
    else // If it has space
    {
        // Asking for new element
        int element;
        printf("Enter new element: ");
        scanf("%d", &element);

        if (element > A[nonzero_count - 1]) // If Element is greater than existing elements, insert at the end
        {
            A[nonzero_count] = element;
        }
        else
        {
            // Finding position to insert new element
            int pos = 0;

            for (int i = 0; i < size; i++)
            {
                if (A[i] <= element)
                {
                    pos++;
                }
                else
                {
                    break;
                }
            }

            // Shifting Array elements to the right
            for (int i = nonzero_count; i >= pos; i--)
            {
                A[i] = A[i - 1];
            }

            // Inserting element at appropriate position
            A[pos] = element;
        }

        // Printing Updated Array
        printf("Updated Array: ");
        print_array(A, size);

        // Searching for element - Binary Search
        int target;
        printf("Enter search element: ");
        scanf("%d", &target);
        int index = Binary_Search(A, size, target);

        if (index == -1)
        {
            printf("Element not found\n");
        }
        else
        {
            printf("Element found at position %d", index+1);
        }
    }
}
