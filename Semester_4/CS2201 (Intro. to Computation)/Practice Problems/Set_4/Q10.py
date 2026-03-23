# QUESTION
# Continue with Q9 to create another dictionary ‘d_sum’ that contains the sum of the marks. So, the corresponding dictionary entry will look like ‘ms1901’: 240.0. To compute sum use numpy function sum() (Note: The sum of a numpy array A is calculated as numpy.sum(A))

import numpy as np

# Parameters
d = {}
num_std = 5
num_courses = 3

# User input for student data
for i in range(num_std):
    roll = input("Enter roll: ")

    # User input for course marks of a student
    for j in range(num_courses):
        course = input("Enter course name: ")
        mark = float(input(f"Enter mark for {course}: "))

        # Store the marks in the dictionary
        if roll in d:
            d[roll][j] = mark
        else:
            d[roll] = np.zeros(num_courses, dtype='float64')
            d[roll][j] = mark

print("Individual marks of all students:", d)

# Sum of marks for each student
for roll in d:
    total = np.sum(d[roll])
    d[roll] = total

print("Total marks of all students:", d)
