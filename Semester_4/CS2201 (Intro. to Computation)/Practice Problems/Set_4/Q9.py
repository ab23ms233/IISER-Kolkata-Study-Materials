# QUESTION
# Input (use input()) the roll number and marks of three courses for 5 students and store it in a dictionary (d) such that the roll number is the key and the marks are stored in a numpy array of type float64 (the type of a numpy array A can be changed to float64 type by A.astype(‘float64’)). For example, for a student with roll number ‘ms1901’ and marks 70, 80, 90, the dictionary entry will look like ‘ms1901’: array([70., 80., 90.])

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
    
print(d)
