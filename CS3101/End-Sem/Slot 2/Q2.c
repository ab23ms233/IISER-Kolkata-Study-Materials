#include <stdio.h>
#include <string.h>

void main() {
    char destination[20];
    char myname[20];

    // Input of name from user
    printf("Enter your name: ");
    fgets(myname, sizeof(myname), stdin);
    myname[strcspn(myname, "\n")] = 0;        // Removing newline character (\n) from myname

    // Input of destination from user
    printf("Enter the name of your favourite destination: ");
    fgets(destination, sizeof(destination), stdin);
    destination[strcspn(destination, "\n")] = 0;

    printf("%s loves %s\n", myname, destination);
}