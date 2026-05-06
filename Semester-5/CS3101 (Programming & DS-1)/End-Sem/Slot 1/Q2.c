#include <stdio.h>
#include <string.h>

void main()
{
	// Taking user input of friend's name
	char friendname[20];
	printf("Enter the name of your best friend: ");
	fgets(friendname, sizeof(friendname), stdin);
	friendname[strcspn(friendname, "\n")] = 0; // Removing "\n" from user input

	// Myname
	char myname[20];
	strcpy(myname, "Arya");

	printf("%s and %s are cool buddies!\n", friendname, myname);
}
