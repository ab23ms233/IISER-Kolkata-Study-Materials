// QUESTION
// Write a program in C programming language to take as input the radius (R) and height (H) of a cone and print the volume on the terminal (formula: volume = PI*r*r*(h/3)).

# include <stdio.h>

void main() {
    float radius, height;
    const float pi = 3.14;

    printf("Enter radius of cone: ");
    scanf("%f", &radius);

    printf("Enter height of cone: ");
    scanf("%f", &height);

    float volume = (float) pi*radius*radius*height/3;
    printf("Volume: %f", volume);
}