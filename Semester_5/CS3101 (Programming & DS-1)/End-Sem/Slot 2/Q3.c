#include <stdio.h>

void main() {
    float weight, height;

    printf("Enter your weight (in kg): ");
    scanf("%f", &weight);
    printf("Enter your height (in m): ");
    scanf("%f", &height);
    printf("\n");
    
    float bmi = (float) weight/(height*height);
    printf("BMI: %f\n", bmi);

    if (bmi < 18.5)
    {
        printf("Underweight\n");
    }
    else if (bmi <= 25)
    {
        printf("Normal\n");
    }
    else if (bmi <= 30)
    {
        printf("Overweight");
    }
    else
    {
        printf("Obese");
    }
    
}