#include <stdio.h>

// Function to print an array
void print_array(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

// Function for taking array input from user
void askArray(int *arr, int size)
{
	int element;

	for (int i = 0; i < size; i++)
	{
		printf("Enter element %d: ", i + 1);
		scanf("%d", &element);

		arr[i] = element;
	}
}

void main()
{
	// Initialising array sizes
	int m, n;

	// Taking user input for array sizes
	printf("Enter the size of array 1: ");
	scanf("%d", &m);
	printf("Enter the size of array 2: ");
	scanf("%d", &n);
	printf("\n");

	// Initialsing the 2 arrays
	int A[m];
	int B[n];

	// Taking user input for array 1 elements
	printf("Array 1\n");
	askArray(A, m);

	// Printing array 1 elements
	printf("\n");
	printf("Array 1: ");
	print_array(A, m);
	printf("\n");

	// Taking user input for array 2 elements
	printf("Array 2\n");
	askArray(B, n);

	// Printing array 2 elements
	printf("\n");
	printf("Array 2: ");
	print_array(B, n);
	printf("\n");

	// Maximum size of the 2 arrays
	int min;

	if (m < n)
	{
		min = m;
	}
	else
	{
		min = n;
	}

	// Defining variables
	int C[min];
	int a = 0;
	int b = 0;
	int c = 0;

	// Checking for intersection of elements
	for (int i = 0; i < m + n; i++)
	{
		if (A[a] > B[b])
		{
			b += 1;
		}
		else if (A[a] < B[b])
		{
			a += 1;
		}
		else
		{
			C[c] = A[a];
			c += 1;
			a += 1;
			b += 1;
		}

		// If one of the arrays is fully traversed
		if (a == m || b == n)
		{
			break;
		}
	}

	// Printing the common elements
	printf("Intersection of Array 1 and Array 2: ");
	print_array(C, c);
}
