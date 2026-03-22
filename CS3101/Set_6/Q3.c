// QUESTION

// Assume that there is a text file “Data1.txt”. Use getc/putc to read it, convert the text to lowercase (use tolower()), and write the resulting text to another file, “Data2.txt”.

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void main() {
    FILE *ptr1 = NULL;
    FILE *ptr2 = NULL;

    ptr1 = fopen("Data1.txt", "r");
    ptr2 = fopen("Data2.txt", "w");

    if (ptr1 == NULL || ptr2 == NULL) {
        printf("Error opening files");
        exit(1);
    }

    char c1 = fgetc(ptr1);
    char c2;

    while (c1 != EOF) {
        c2 = tolower(c1);
        fputc(c2, ptr2);
        c1 = fgetc(ptr1);
    }

    printf("Data recorded successfully\n");
    fclose(ptr1);
    fclose(ptr2);
}
