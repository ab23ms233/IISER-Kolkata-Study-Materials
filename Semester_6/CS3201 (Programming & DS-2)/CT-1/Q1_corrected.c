#include <stdio.h>
#include <stdlib.h>

void initialize_array(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = i*10;
	}
}

int main()
{
	int size = 10;
	
	// Allocate memory for 10 integers
	int *numbers = (int *) malloc(size * sizeof(int));
	
	// Check if allocation was successful
	if (numbers == NULL)
	{
		printf("Memory allocation failed!\n");
		return 1;
	}
	
	// Initialise the array
	initialize_array(numbers, size);
	
	numbers[size-1] = 999;
	free(numbers);	// free heap memory
	return 0;
}
