// QUESTION
// Write a program to calculate the electricity bill based on the units and the rates as given below, with an appropriate decision-making structure (e.g., if-else-if). The units (an integer) will be taken as input from the user, and the total bill (using “%f”), based on the rate, in Rs. will be printed on the terminal.

// Units
// Rate (Rs. per unit)
// First 25
// 4.89
// Next 35
// 5.40
// Next 40
// 6.41
// Next 50
// 7.16
// Next 50
// 7.33
// Next 100
// 7.33
// Above 300
// 8.92

#include <stdio.h>

void main() {
    int units;
    float cost;

    printf("Enter the number of units: ");
    scanf("%d", &units);

    if (units <= 25)
    {
        cost = units*4.89;
    }
    else
    {
        cost = 25*4.89;     // 1st 25 units

        if (units <= 60)
        {
            cost += (units-25)*5.4;
        }
        else
        {
            cost += 35*5.4;     // Next 35 units

            if (units <= 100)
            {
                cost += (units-60)*6.41;
            }
            else
            {
                cost += 40*6.41;        // Next 40 units

                if (units <= 150)
                {
                    cost += (units-100)*7.16;
                }
                else
                {
                    cost += 50*7.16;        // Next 50 units

                    if (units <= 300)
                    {
                        cost += (units-150)*7.33;
                    }
                    else
                    {
                        cost += 150*7.33 + (units-300)*8.92;        // Rest 150 and remaining units
                    }
                }
            }
        }
    }

    printf("Total Cost: %f", cost);
}
