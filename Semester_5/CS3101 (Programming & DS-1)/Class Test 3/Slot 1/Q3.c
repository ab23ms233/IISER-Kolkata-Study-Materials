#include <stdio.h>
#include "myheader.h"	// Header File

void main()
{
	// Initialising Variables
	int real_1, real_2;
	int complex_1, complex_2;
	
	// Taking user input for complex numbers
	printf("Enter real part of num 1: ");
	scanf("%d", &real_1);
	printf("Enter complex part of num 1: ");
	scanf("%d", &complex_1);
	printf("\n");
	
	printf("Enter real part of num 2: ");
	scanf("%d", &real_2);
	printf("Enter complex part of num 2: ");
	scanf("%d", &complex_2);
	printf("\n");
	
	// Declaring andf initialising complex number arrays
	int element_0[] = {real_1, complex_1};
	int element_1[] = {real_2, complex_2};
	
	// Function call from myheader.h
	int *ptr = addComplex(element_0, element_1);
	
	// Printing output
	printf("Sum of real parts: %d\n", ptr[0]);
	printf("Sum of complex parts: %d\n", ptr[1]);
}
