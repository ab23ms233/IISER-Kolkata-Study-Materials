#include <stdio.h>
#include <string.h>

// Function to check subsequence
int IsSubsequence(char *sub, char *str) 
{
	int i = 0;
	int j = 0;
	
	// Traversing str
	while (str[i])
	{
		if (str[i] == sub[j])
		{
			j++;
		}
		
		i++;
	}
	
	// If j reaches the end of sub, it is a subsequence 
	if (sub[j] == '\0')
	{
		return 1;
	}
	
	return 0;
}


void main()
{
	char sub[10];
	char str[20];
	
	// String input from user
	printf("Enter string: ");
	fgets(str, sizeof(str), stdin);
	str[strcspn(str, "\n")] = 0;
	
	// Sub string input from user
	printf("Enter sub-string to check: ");
	fgets(sub, sizeof(sub), stdin);
	sub[strcspn(sub, "\n")] = 0;
	printf("\n");
	
	int result = IsSubsequence(sub, str);
	
	if (result == 1)
	{
		printf("%s is a subsequence of %s\n", sub, str);
	}
	else
	{
		printf("%s is NOT a subsequence of %s\n", sub, str);
	}
}
