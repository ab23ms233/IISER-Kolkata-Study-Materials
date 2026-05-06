#include <stdio.h>
#include <stdlib.h>
#include "SinglyLinkedList.h"

// Function for summing the values of a Linked List
int sumList(node *start)
{
	node *p;
	int sum = 0;
	
	// Traversing the list
	p = start;
	while (p != NULL)
	{
		sum += p->info;		// Summing the elements
		p = p->link;
	}
	
	return sum;
}


void main()
{
	int num, ch;
	
	// User input for number
	printf("Enter the number: ");
	scanf("%d", &num);
	while ((ch = getchar()) != '\n' && ch != EOF);	// Clearing leftover \n from input buffer
	
	// Retrieving digits of the number and storing them in a Linked List
	int rem;
	node *start = NULL;
	while (num != 0)
	{
		rem = num%10;
		start = addatbeg(start, rem);
		num = (int) num/10;
	}
	
	// Printing the Linked List
	printf("Linked List: ");
	display(start);
	printf("\n");
	
	// Checking if number is divisible by 3
	int sum = sumList(start);
	
	if (sum%3 == 0)
	{
		printf("The number is divisible by 3\n");
	}
	else
	{
		printf("The number is NOT divisible by 3\n");
	}
	
}
