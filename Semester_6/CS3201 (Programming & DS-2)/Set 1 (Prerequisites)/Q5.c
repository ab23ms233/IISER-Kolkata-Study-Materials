// QUESTION

// Consider a database of student records (stored in a structure): name (a multi-word string), id (integer), marks in three subjects as a static array of floating point numbers, average marks (float), and grade letter (string). 
// Take name, id, and marks in three subjects as input from the user in a function inputStudentData() that takes a pointer to an array of structures as an argument. 
// Then pass this pointer as an argument to the function calculateStatistics() to compute the average marks and grade letter (for the latter use IISER-K standard grade boundaries) in the structure. 
// Display all information for all the students by calling a function printallStudents() that takes the same pointer as an argument. 


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Student Structure
typedef struct Student
{
    char name[50];
    int id;
    float marks[3];
    float average;
    char grade[3];
} student;

// Function for taking user input of student data
void inputStudentData(student *ptr, int size)
{
    char name[50];
    int id;
    int ch;
    float mark, marks[3];

    // Taking input for various fields
    for (int i = 0; i < size; i++)
    {
        // Name
        printf("Enter name: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = 0;
        strcpy((ptr+i)->name, name);

        // ID
        printf("Enter ID: ");
        scanf("%d", &id);
        while ((ch = getchar()) != '\n' && ch != EOF);      // Clearing input buffer leftover from scanf
        (ptr+i)->id = id;

        // Marks
        for (int j = 0; j < 3; j++)
        {
            printf("Enter mark %d: ", j+1);
            scanf("%f", &mark);
            while ((ch = getchar()) != '\n' && ch != EOF);      // Clearing input buffer leftover from scanf

            (ptr+i)->marks[j] = mark;
        }
        printf("\n");

        // Printing recorded data for checking
        // printf("Name: %s\n", (ptr+i)->name);
        // printf("ID: %d\n", (ptr+i)->id);
        // printf("Marks: %f %f %f\n", (ptr+i)->marks[0], (ptr+i)->marks[1], (ptr+i)->marks[2]);
        // printf("\n");
    }
}

// Function for calculating average marks and grade letter
void calculateStatistics(student *ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        float sum = 0, avg = 0;
        char grade[3];

        // Calculating average
        for (int j = 0; j < 3; j++)
        {
            sum += (ptr+i)->marks[j];
        }

        avg = (float) sum/3;
        (ptr+i)->average = avg;

        // Calculating grade letter
        if (avg < 40)
        {
            strcpy(grade, "F");
        }
        else if (avg >= 40 && avg < 50)
        {
            strcpy(grade, "D");
        }
        else if (avg >= 50 && avg < 60)
        {
            strcpy(grade, "C");
        }
        else if (avg >= 60 && avg < 70)
        {
            strcpy(grade, "B");
        }
        else if (avg >= 70 && avg < 80)
        {
            strcpy(grade, "B+");
        }
        else if (avg >= 80 && avg < 90)
        {
            strcpy(grade, "A");
        }
        else
        {
            strcpy(grade, "A+");
        }

        strcpy((ptr+i)->grade, grade);
    }
}

// Printing data of all students
void printallStudents(student *ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Name: %s\n", (ptr+i)->name);
        printf("ID: %d\n", (ptr+i)->id);
        printf("Marks: %f %f %f\n", (ptr+i)->marks[0], (ptr+i)->marks[1], (ptr+i)->marks[2]);
        printf("Average Marks: %f\n", (ptr+i)->average);
        printf("Grade: %s\n", (ptr+i)->grade);
        printf("\n");
    }    
}

void main()
{
    // User input for number of students
    int numOfStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numOfStudents);
    printf("\n");
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);      // Clearing input buffer leftover from scanf

    // Initialising student struct and pointer
    student students[numOfStudents];
    student *ptr = students;

    // Calling all functions
    inputStudentData(ptr, numOfStudents);
    calculateStatistics(ptr, numOfStudents);
    printallStudents(ptr, numOfStudents);
}