// QUESTION

// Write a C program to take any string (e.g. “Programming in C language”) and define two functions: i) count(): that counts the number of occurrences of a character in the string (e.g. it returns 3 for ‘a’ in the example string) and ii) replace(): that replaces a character in the input string with another character (e.g. for the input string if ‘a’ is to be replaced with ‘z’, the resulting output string should be “Progrzmming in C lznguzge”). You should pass the string as a pointer to these two functions. Use of a global variable is NOT allowed.

#include <stdio.h>
#include <string.h>

// Function to calculate number of occurences of 'counting_char' in string with pointer str_ptr 
int count(const char *str_ptr, char counting_char)
{
    int count = 0;
    int i = 0;

    while (str_ptr[i])
    {
        if (str_ptr[i] == counting_char)
        {
            count++;
        }

        i++;
    }

    return count;
}

// Function to replace a character (character_to_replace) by another character (replacing_char) in string with pointer str_ptr
void replace(char *str_ptr, char character_to_replace, char replacing_char)
{
    int i = 0;

    while (str_ptr[i])
    {
        if (str_ptr[i] == character_to_replace)
        {
            str_ptr[i] = replacing_char;
        }

        i++;
    }
}


void main()
{
    char str[40];
    char counting_char;
    char character_to_replace;
    char replacing_char;

    char *ptr = str;
    // strcpy(str, "Programming in C language");

    printf("Enter string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // To remove trailing newline character

    printf("Enter character to count: ");
    scanf(" %c", &counting_char);
    printf("\n");

    int character_count = count(ptr, counting_char);
    printf("Count of '%c' in '%s': %d\n", counting_char, str, character_count);
    printf("\n");

    printf("Enter character to replace in the string: ");
    scanf(" %c", &character_to_replace);
    printf("Enter replacement character: ");
    scanf(" %c", &replacing_char);
    printf("\n");

    replace(ptr, character_to_replace, replacing_char);
    printf("String after replacement: %s", str);
}
