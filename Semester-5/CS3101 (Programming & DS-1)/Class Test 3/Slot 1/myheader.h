#include <stdio.h>

int sum[2];	// Defining global variable

int *addComplex(int *arr1, int *arr2)
{
	sum[0] = arr1[0] + arr2[0];	// Real Part sum
	sum[1] = arr1[1] + arr2[1];	// Complex Part sum
	
	return sum;
}
