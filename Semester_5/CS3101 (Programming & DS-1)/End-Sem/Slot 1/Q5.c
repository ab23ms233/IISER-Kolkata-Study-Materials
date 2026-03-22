#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define size 5

// struct for storing vegetable information
typedef struct Vegetable
{
	char name[20];
	int quantity;
	int price;
} VEGETABLE;

// Function for writing to file
void fileWrite(char *filename, VEGETABLE *vegetables)
{
	FILE *ptr = NULL;
	ptr = fopen(filename, "w");

	if (ptr == NULL)
	{
		printf("Error opening file\n");
		exit(1);
	}

	for (int i = 0; i < size; i++)
	{
		fwrite(&vegetables[i], sizeof(VEGETABLE), 1, ptr);
		fputc('\n', ptr); // Insert a newline after every vegetable
	}

	fclose(ptr);
}

// Function for reading from file
void fileRead(char *filename, VEGETABLE *vegetables)
{
	FILE *ptr;
	ptr = fopen(filename, "r");

	if (ptr == NULL)
	{
		printf("Error opening file\n");
		exit(1);
	}

	int i = 0;
	while (fread(&vegetables[i], sizeof(VEGETABLE), 1, ptr))
	{
		// printf("Name: %s\n", vegetables[i].name);
		// printf("Quantity: %d\n", vegetables[i].quantity);
		// printf("Price: %d\n", vegetables[i].price);
		i++;
		fseek(ptr, 1, 1); // Skip the newline after every vegetable
	}

	fclose(ptr);
}

// Function for printing an array of VEGETABLE struct
void print_vegetables(VEGETABLE *vegetables)
{
	for (int i = 0; i < size; i++)
	{
		printf("Name: %s\n", vegetables[i].name);
		printf("Quantity: %d\n", vegetables[i].quantity);
		printf("Price: %d\n", vegetables[i].price);
		printf("\n");
	}
}

void main()
{
	// Defining an array of struct vegetable
	VEGETABLE vegetables_to_write[size] = {{"Potato", 5, 10},
										   {"Onion", 7, 15},
										   {"Ladies Finger", 10, 5},
										   {"Spinach", 6, 20},
										   {"Carrot", 12, 15}};

	char filename[] = "MyVegetables.txt";

	// Writing to file
	fileWrite(filename, vegetables_to_write);

	// Reading from file
	VEGETABLE vegetables[size];
	fileRead(filename, vegetables);

	// Defining variables
	int choice;
	int repeat = 1;
	char name[20];
	int price;
	int quantity;
	int total = 0;
	int available;
	int individual_total;

	// Welcome message
	printf("Welcome to The Vegetable Store!\n");
	printf("\n");

	// do-while loop
	do
	{
		// Displaying buying options to the user
		printf("Choose from one of the following\n");
		for (int i = 0; i < size; i++)
		{
			strcpy(name, vegetables[i].name);
			price = vegetables[i].price;

			printf("%d. %s - Rs. %d/qty\n", i + 1, name, price);
		}

		// User input for vegetable choice
		scanf("%d", &choice);
		printf("\n");

		available = vegetables[choice - 1].quantity; // How many vegetables of choice are available
		strcpy(name, vegetables[choice - 1].name);	 // Name of choice vegetable

		switch (choice)
		{
		// Potato
		case 1:
			printf("You choose to buy %s!\n", name);
			printf("Enter quantity: ");
			scanf("%d", &quantity);

			// If sufficient quantity is not available
			if (quantity > available)
			{
				printf("Only %d units are available\n", available);
			}
			else
			{
				price = vegetables[choice - 1].price;
				individual_total = quantity * price;
				total += individual_total;					 // Update total
				vegetables[choice - 1].quantity -= quantity; // Update stock

				printf("Total price for %s: %d\n", name, individual_total);
			}
			break;

		// Onion
		case 2:
			printf("You choose to buy %s!\n", name);
			printf("Enter quantity: ");
			scanf("%d", &quantity);

			if (quantity > available)
			{
				printf("Only %d units are available\n", available);
			}
			else
			{
				price = vegetables[choice - 1].price;
				individual_total = quantity * price;
				total += individual_total;
				vegetables[choice - 1].quantity -= quantity;

				printf("Total price for %s: %d\n", name, individual_total);
			}
			break;

		// Ladies Finger
		case 3:
			printf("You choose to buy %s!\n", name);
			printf("Enter quantity: ");
			scanf("%d", &quantity);

			if (quantity > available)
			{
				printf("Only %d units are available\n", available);
			}
			else
			{
				price = vegetables[choice - 1].price;
				individual_total = quantity * price;
				total += individual_total;
				vegetables[choice - 1].quantity -= quantity;

				printf("Total price for %s: %d\n", name, individual_total);
			}
			break;

		// Spinach
		case 4:
			printf("You choose to buy %s!\n", name);
			printf("Enter quantity: ");
			scanf("%d", &quantity);

			if (quantity > available)
			{
				printf("Only %d units are available\n", available);
			}
			else
			{
				price = vegetables[choice - 1].price;
				individual_total = quantity * price;
				total += individual_total;
				vegetables[choice - 1].quantity -= quantity;

				printf("Total price for %s: %d\n", name, individual_total);
			}
			break;

		// Carrot
		case 5:
			printf("You choose to buy %s!\n", name);
			printf("Enter quantity: ");
			scanf("%d", &quantity);

			if (quantity > available)
			{
				printf("Only %d units are available\n", available);
			}
			else
			{
				price = vegetables[choice - 1].price;
				individual_total = quantity * price;
				total += individual_total;
				vegetables[choice - 1].quantity -= quantity;

				printf("Total price for %s: %d\n", name, individual_total);
			}
			break;

		// Wrong Input
		default:
			printf("Wrong Choice!\n");
			break;
		}
		printf("\n");

		// Whether user wants to continue buying
		printf("Do you wish to continue buying?\n");
		printf("1. Yes\n");
		printf("2. No\n");

		scanf("%d", &repeat);
		printf("\n");

	} while (repeat == 1);

	// Total for all purchases
	printf("Total Price for all vegetables: %d\n", total);
	printf("Thank you for buying from us\n");
	printf("\n");

	// Writing updated stock to file
	fileWrite(filename, vegetables);

	// Reading from file
	VEGETABLE vegetables_to_read[size];
	fileRead(filename, vegetables_to_read);

	// Printing Updated Stock
	printf("Updated Stock\n");
	printf("\n");
	print_vegetables(vegetables_to_read);
}
