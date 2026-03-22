#include <stdio.h>

void main()
{
	int num1, num2, num3;

	// Taking user input for 3 numbers
	printf("Enter number 1: ");
	scanf("%d", &num1);
	printf("Enter number 2: ");
	scanf("%d", &num2);
	printf("Enter number 3: ");
	scanf("%d", &num3);
	printf("\n");

	// Calculating average
	float average = (float)(num1 + num2 + num3) / 3;
	printf("Average: %f\n", average);
}
