// QUESTION
// Write a program in C to calculate the Gravitation Force (F) between two objects of masses M1 and M2 (Formula: F = (G*M1*M2)/(R*R), G = 6.673 x 10-11, R is the distance between the two centres of masses of the two objects) such that G is i) a macro (#define), ii) local variable, iii) global variable.

#include <stdio.h>


// PART 1 - Macro (#define)

// #define G 6.673e-11

// void main() {
//     float m1, m2, r;

//     printf("Enter mass of body 1 (in kg): ");
//     scanf("%f", &m1);

//     printf("Enter mass of body 2 (in kg): ");
//     scanf("%f", &m2);

//     printf("Enter distance between the 2 bodies (in m): ");
//     scanf("%f", &r);

//     float F = (G*m1*m2)/(r*r);
//     printf("Force (in N): %0.10f", F);
// }


// PART 2 - Local Variable

// void main() {
//     double G = 6.673e-11;
//     float m1, m2, r;

//     printf("Enter mass of body 1 (in kg): ");
//     scanf("%f", &m1);

//     printf("Enter mass of body 2 (in kg): ");
//     scanf("%f", &m2);

//     printf("Enter distance between the 2 bodies (in m): ");
//     scanf("%f", &r);

//     float F = (G*m1*m2)/(r*r);
//     printf("Force (in N): %0.10f", F);
// }


// PART 3 - Global Variable

float G = 6.673e-11;

void main() {
    float m1, m2, r;

    printf("Enter mass of body 1 (in kg): ");
    scanf("%f", &m1);

    printf("Enter mass of body 2 (in kg): ");
    scanf("%f", &m2);

    printf("Enter distance between the 2 bodies (in m): ");
    scanf("%f", &r);

    float F = (G*m1*m2)/(r*r);
    printf("Force (in N): %0.10f", F);
}
