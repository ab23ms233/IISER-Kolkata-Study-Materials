#include <stdio.h>

// Function for calculating sum of squares
int SqSum(int n)
{
	if (n == 1)
	{
		return 1;
	}
	
	return n*n + SqSum(n-1);	// Recursive Logic
}

void main()
{
	int n;
	
	// Taking user input
	printf("Enter the number of terms for summing: ");
	scanf("%d", &n);
	
	// Function Call
	int result = SqSum(n);
	printf("The value of squared sum is %d\n", result);
}
