#include <stdio.h>
#include <string.h>

#define count 10

// Defining student struct
struct STUDENT
{
    char name[20];
    int ID;
    float CGPA;
    char major[10];
};

// Function to print data of 1 student
void print_student(const struct STUDENT student)
{
    printf("Name: %s\n", student.name);
    printf("ID: %d\n", student.ID);
    printf("CGPA: %f\n", student.CGPA);
    printf("Major: %s\n", student.major);
    printf("\n");
}

// Function to find out ID of student with max CGPA for a given major
// Time complexity - O(n)
int retMaxID(struct STUDENT *students, char *major)
{
    int max;    // To store max CGPA
    int id;     // To store ID of max CGPA  
    int found = 0;      // found = 1 if student with given major is found

    for (int i = 0; i < count; i++)
    {
        // If student with given major is found
        if (strcmp(students[i].major, major) == 0)
        {
            found = 1;

            // If given student has CGPA > max
            if (students[i].CGPA > max)
            {
                max = students[i].CGPA;     // Update max
                id = students[i].ID;        // Store ID of student in id
            }
        }
    }

    if (found)
    {
        return id;
    }

    return -1;
}

void main()
{
    struct STUDENT students[count];
    int initial_CGPA = 5;

    char majors[][10] = {"Maths", "Physics", "Biology",
                         "Chemistry", "ES"};
    char names[count][20] = {"Arya", "Soham", "Krishna",
                             "Anuvansh", "Shyam", "Ananya",
                             "Khushant", "Ashutosh", "Saswat", "Pratik"};
    
    // Defining ID, CGPA and Major for count students
    for (int i = 0; i < count; i++)
    {
        strcpy(students[i].name, names[i]);
        students[i].ID = i + 1;
        students[i].CGPA = initial_CGPA + (strlen(names[i])%5);
        strcpy(students[i].major, majors[i % 5]);
    }

    // Printing student database
    printf("Student Database: \n");
    printf("\n");

    for (int i = 0; i < count; i++)
    {
        print_student(students[i]);
    }

    // Reading major from user
    char major[10];
    printf("Enter major to search for max CGPA: ");
    fgets(major, sizeof(major), stdin);
    major[strcspn(major, "\n")] = 0;

    // Calling retMaxID
    int max_id = retMaxID(students, major);
    printf("Max CGPA is of ID: %d", max_id);
}