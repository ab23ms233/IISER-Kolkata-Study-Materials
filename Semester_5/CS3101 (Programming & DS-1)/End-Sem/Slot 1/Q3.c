#include <stdio.h>

// Function to check whether 3 sides constitute a valid triangle
// Returns 1 if triangle is possible
// Returns 0 otherwise
int isTriangle(int side1, int side2, int side3)
{
	if (side1 + side2 < side3 || side2 + side3 < side1 || side3 + side1 < side2)
	{
		return 0;
	}

	return 1;
}

void main()
{
	int side1, side2, side3;

	// Taking user input for sides of the triangle so that all cases can be checked at once
	printf("Enter side 1: ");
	scanf("%d", &side1);
	printf("Enter side 2: ");
	scanf("%d", &side2);
	printf("Enter side 3: ");
	scanf("%d", &side3);
	printf("\n");

	// If triangle is possible
	if (isTriangle(side1, side2, side3))
	{
		if (side1 == side2 && side3 == side2)
		{
			printf("Equilateral Triangle\n");
		}
		else if (side1 == side2 || side2 == side3 || side3 == side1)
		{
			printf("Isosceles Triangle\n");
		}
		else
		{
			printf("Scalene Triangle\n");
		}
	}

	// If triangle is not possible
	else
	{
		printf("Triangle is not possible with the given side lengths\n");
	}
}
