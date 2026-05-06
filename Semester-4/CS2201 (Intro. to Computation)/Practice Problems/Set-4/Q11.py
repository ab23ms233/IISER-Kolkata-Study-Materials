# QUESTION
# Check if two 1-D numpy arrays are equal or not using a for loop. Verify the result with the numpy function numpy.array_equal(a1, a2) that returns True if the arrays a1, a2 are equal

import numpy as np

# User input for arrays
l1 = eval(input("Enter list 1: "))
l2 = eval(input("Enter list 2: "))
arr1, arr2 = np.array(l1), np.array(l2)

# Checking for similarity
if len(arr1) == len(arr2):
    for i in range(len(arr1)):
        if arr1[i] != arr2[i]:
            print("The 2 arrays are not equal")
            break
    else:
        print("The 2 arrays are equal")
else:
    print("The 2 arrays are not equal")

# np.array_equal output
print(np.array_equal(arr1, arr2))