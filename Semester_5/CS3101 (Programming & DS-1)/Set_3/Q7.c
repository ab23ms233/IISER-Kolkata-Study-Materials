// QUESTION
// An integer n when divided by another integer d (>0) belongs to exactly one of the mod d equivalence classes (Zd) {[0], [1], [2], … [d-1]} where [i] (i being an integer) is the set of all integers with reminder i when divided by d such that i = 0, 1, 2, …, d - 1. That is, if n = 20, d = 5, n will belong to the class [0]; if n = 21, d = 5, n will belong to [1], and so on. Design a C program to print the mod d equivalent class of n using switch case. Note that it doesn’t need to be a generic solution for any d (no need to take ‘n’ and ‘d’ as user inputs, and you can have fixed n, d values).

#include <stdio.h>

void main() {
    int num = 20, divisor = 5;
    int remainder = num%divisor;

    switch (remainder)
    {
    case 0:
        printf("Class: [0]");
        break;
    case 1:
        printf("Class: [1]");
        break;
    case 2:
        printf("Class: [2]");
        break;
    case 3:
        printf("Class: [3]");
        break;
    case 4:
        printf("Class: [4]");
        break;
    }
}
