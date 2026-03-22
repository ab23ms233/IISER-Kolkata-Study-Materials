// QUESTION
// Write a C program to take the name (e.g., Kripa) and age (41) (supposing your name is “Sachin” and your age is 50) as input from the user and print a message on the terminal: “Hello Kripa, you are 41 years old. I am Sachin, I am 50 years old”.

# include <stdio.h>

void main() {
    int age;
    char name[25];

    printf("Enter your name: ");
    scanf("%s", &name);

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Hello %s, you are %d years old. I am Arya, I am 20 years old", name, age);
}
