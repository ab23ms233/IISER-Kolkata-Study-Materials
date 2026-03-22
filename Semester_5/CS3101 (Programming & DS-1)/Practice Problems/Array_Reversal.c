#include <stdio.h>

void array_reversal(int *arr, int size)
{
    int temp;

    for (int i = 0; i < size / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

void print_array(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void main()
{
    int array[] = {1, 3, 5, 7, 9, 11, 13};
    int size = (int) sizeof(array) / sizeof(array[0]);

    printf("Original Array: ");
    print_array(array, size);

    array_reversal(array, size);
    printf("Reversed Array: ");
    print_array(array, size);
}