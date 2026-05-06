#include <stdio.h>
#include <stdlib.h>
#include "SinglyLinkedList.h"

// Function to alternate nodes of 2 linked lists
node *alternateList(node *start1, node *start2)
{
	node *tmp1, *tmp2, *p1, *p2;
	
	// p1 and p2 are used to traverse the 2 lists
	p1 = start1;
	p2 = start2;
	
	while (p1 != NULL && p2 != NULL)
	{
		if (p1->link == NULL)
		{
			p1->link = p2;
			return start1;
		}
		
		// tmp1 and tmp2 store the next nodes after p1 and p2
		tmp1 = p1->link;
		p1->link = p2;
		tmp2 = p2->link;
		p2->link = tmp1;
		
		p1 = tmp1;
		p2 = tmp2;
	}
	
	return start1;
}


void main()
{
	int num, ch, element;
	node *start1 = NULL, *start2 = NULL;
	
	// IF LISTS ARE CREATED FROM PRE-DEFINED ARRAYS
	// Predefined arrays for creating 2 linked lists
	/*int l1 = 5;
	int l2 = 2;
	
	int arr1[] = {1, 2, 3, 4, 5};
	int arr2[] = {6, 7};
	
	// Adding elements to List 1
	for (int i = 0; i < l1; i++)
	{
		if (i == 0)
		{
			start1 = addatbeg(start1, arr1[i]);
		}
		else
		{
			start1 = addatend(start1, arr1[i]);
		}
	}
	
	// Adding elements to List 2
	for (int i = 0; i < l2; i++)
	{
		if (i == 0)
		{
			start2 = addatbeg(start2, arr2[i]);
		}
		else
		{
			start2 = addatend(start2, arr2[i]);
		}
	}*/
	
	// IF LISTS ARE CREATED FROM USER INPUT
	// LIST 1 
	printf("LIST 1\n");
	printf("--------------\n");

	// Number of elements
	printf("Enter the number of elements: ");
	scanf("%d", &num);
	while ((ch = getchar()) != '\n' && ch != EOF);	// Clearing leftover \n from input buffer
	printf("\n");
	
	// User input for elements of list and adding them to a Linked List
	for (int i = 0; i < num; i++)
	{
		printf("Enter element %d: ", i+1);
		scanf("%d", &element);
		
		if (i == 0)
		{
			start1 = addatbeg(start1, element);
		}
		else
		{
			start1 = addatend(start1, element);
		}
	}
	printf("\n");
	
	// Displaying elements of the List
	printf("List 1: ");
	display(start1);
	printf("\n");
	
	
	// LIST 2
	printf("LIST 2\n");
	printf("--------------\n");
	
	// Number of elements
	printf("Enter the number of elements: ");
	scanf("%d", &num);
	while ((ch = getchar()) != '\n' && ch != EOF);	// Clearing leftover \n from input buffer
	printf("\n");
	
	// User input for elements of list and adding them to a Linked List
	for (int i = 0; i < num; i++)
	{
		printf("Enter element %d: ", i+1);
		scanf("%d", &element);
		
		if (i == 0)
		{
			start2 = addatbeg(start2, element);
		}
		else
		{
			start2 = addatend(start2, element);
		}
	}
	printf("\n");
	
	// Displaying elements of the List
	printf("List 2: ");
	display(start2);
	printf("\n");
	
	// Alternating nodes of the list
	start1 = alternateList(start1, start2);
	printf("Combined List: ");
	display(start1);
	printf("\n");
	
}
