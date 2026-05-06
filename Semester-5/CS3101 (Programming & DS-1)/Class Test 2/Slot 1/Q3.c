#include <stdio.h>
#include <string.h>

// Function to convert integer string to integer
// Return -1 if there is a non-integer in string
int atoi(char *str_ptr)
{
    int i = 0;
    int ascii = 0;
    int num = 0;

    while (str_ptr[i])
    {
        ascii = str_ptr[i] - '0';

        // If there is a non-integer in string, return -1
        if (ascii > 9 || ascii < 0)
        {
            return -1;
        }

        num = num * 10 + ascii;
        i++;
    }

    return num;
}


void main()
{
    // Reading string from user
    char str[5];
    printf("Enter integer string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;

    int num = atoi(str);

    if (num == -1)
    {
        printf("String contains non-integer values");
    }
    else
    {
        printf("Integer: %d", num);
    }
}