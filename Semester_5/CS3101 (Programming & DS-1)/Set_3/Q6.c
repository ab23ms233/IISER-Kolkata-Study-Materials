// QUESTION
// Consider a Genie standing in front of the treasure door. The Genie asks you a puzzle, e.g., “The day before two days after the day before tomorrow is Saturday. What day is it today?” with four options like a) Sunday, b) Monday….. The Genie lets you in only if the answer is correct; else imprisons you. Implement this scheme using switch-case, where you print messages based on success, failure, or invalid answer. 

// Can you also do it using a maximum of three “break”s?


#include <stdio.h>

void main() {
    printf("Solve the given puzzle\n");
    printf("The day before two days after the day before tomorrow is Saturday. What day is it today?\n");

    printf("\n");
    printf("Options: \n");
    printf("a) Sunday\n");
    printf("b) Monday\n");
    printf("c) Friday\n");      // Correct Answer
    printf("d) Thursday\n");
    printf("\n");

    char option;
    printf("Enter option (a-d): ");
    scanf(" %c", &option);

    switch (option)
    {
    case 'c':
        printf("Correct! You found the treasure.");
        break;

    case 'a':
    case 'b':

    case 'd':
        printf("Wrong answer! You are imprisoned.");        // a, b and d are wrong answers. So the case continues until it encounters a break at d
        break;
    
    default:
        printf("Incoreect option choice");
        break;
    }
}