#include <stdio.h>

int left(int arr[], int index)
{
    return 2*index+1;
}

int right(int arr[], int index)
{
    return 2*index+2;
}

void maxHeapify(int arr[], int size, int index)
{
    int largest = index;
    int l = left(arr, index);
    int r = right(arr, index);

    if (l <= size && arr[index]<arr[l]) 
        largest = l;
    if (r <= size && arr[largest]<arr[r])
        largest = r;
    
    if (largest != index)
    {
        int temp = arr[index];
        arr[index] = arr[largest];
        arr[largest] = temp;
        maxHeapify(arr, size, largest);
    }
}
void main()
{
    
}