// QUESTION

// Consider a database of students allocated dynamically. Each student has an id and some courses, stored as a structure element. Here, both id (as a pointer to char) and courses (as a pointer-to-pointer to char) are allocated dynamically, where the courses (and the number of such courses) can be different for different students. Also, you don’t know in advance the number of students, which you need to ask the user. Write a program that takes the aforementioned information from the user for some students and prints them all via a display function print_stu() that takes the database (as a pointer to a structure) as arguments.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct STUDENT
{
    char *std_id;
    int num_courses;
    char **course_ids;
} student;

// Function to input student data from user 
void inputStudentdata(student *ptr, int size)
{
    char sid[10], cid[10];
    int nc, ch;

    for (int i = 0; i < size; i++)
    {
        printf("STUDENT %d\n", i+1);
        printf("--------------\n");

        // Input of Student ID
        printf("Enter ID of Student %d: ", i+1);
        fgets(sid, sizeof(sid), stdin);
        sid[strcspn(sid, "\n")] = 0;

        // Dynamic Allocation of Student ID 
        (ptr+i)->std_id = malloc((strlen(sid)+1)*sizeof(char));
        strcpy((ptr+i)->std_id, sid);

        // Input for number of courses
        printf("Enter the number of courses: ");
        scanf("%d", &nc);
        while ((ch = getchar()) != '\n' && ch != EOF);      // Clearing input buffer before fgets, since scanf leaves \n at the end
        (ptr+i)->num_courses = nc;
        printf("\n");

        // Dynamic memory allocation for array of course ids 
        (ptr+i)->course_ids = malloc(nc*sizeof(char *));

        // Taking user input for course IDs 
        for (int j = 0; j < nc; j++)
        {
            // Input for course id 
            printf("Course ID for course %d: ", j+1);
            fgets(cid, sizeof(cid), stdin);
            cid[strcspn(cid, "\n")] = 0;

            // Dynamic memory allocation for course id 
            (ptr+i)->course_ids[j] = malloc((strlen(cid) + 1)*sizeof(char));
            strcpy((ptr+i)->course_ids[j], cid);
        }
        printf("\n");
    } 
}

// Function for Printing Student Data 
void print_stu(student *ptr, int size)
{
    int nc;

    for (int i = 0; i < size; i++)
    {
        nc = (ptr+i)->num_courses;

        printf("STUDENT %d\n", i+1);
        printf("--------------\n");

        // Printing and freeing up student ID 
        printf("Id: %s\n", (ptr+i)->std_id);
        free((ptr+i)->std_id);

        // Number of courses 
        printf("Number of courses: %d\n", nc);
        printf("\n");

        printf("Courses:\n");

        // Printing and freeing up number of courses 
        for (int j = 0; j < nc; j++)
        {
            printf("%d. %s\n", j+1, (ptr+i)->course_ids[j]);
            free((ptr+i)->course_ids[j]);
        }
        printf("\n");
    }
}


void main()
{
    // Input for number of students 
    int num_std, ch;
    printf("Enter the number of students: ");
    scanf("%d", &num_std);
    while ((ch = getchar()) != '\n' && ch != EOF);
    printf("\n");

    // Dynamic memory allocation for array of student pointers 
    student *studs = malloc(num_std*sizeof(student));

    inputStudentdata(studs, num_std);
    printf("\n");
    print_stu(studs, num_std);
}
