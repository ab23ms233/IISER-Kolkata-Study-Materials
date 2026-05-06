#include <stdio.h>

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
    int size = 8;
    int arr[size];
    int element;

    // Taking user input for array elements
    for (int i = 0; i < size; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &element);

        arr[i] = element;
    }
    printf("\n");

    // Printing array
    printf("Original Array: ");
    print_array(arr, size);

    // Taking user input of sum
    int sum;
    printf("Enter sum to check: ");
    scanf("%d", &sum);

    // Checking if sum exists
    int low = 0;
    int high = size - 1;
    int found = 0;      // found = 0 if sum is not found; found = 1 if sum is found

    for (int i = 0; i < size - 1; i++)
    {
        if (arr[low] + arr[high] == sum)
        {
            found = 1;
            break;
        }
        else if (arr[low] + arr[high] > sum)
        {
            high--;
        }
        else
        {
            low++;
        }
    }

    // If sum is not found
    if (found == 0)
    {
        printf("Elements with sum does not exist");
    }
    else
    {
        printf("Elements with sum are %d and %d", arr[low], arr[high]);
    }
}