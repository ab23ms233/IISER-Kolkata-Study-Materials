# QUESTION
# Create a 2-D NumPy array or matrix of dimension . Now, use array slicing to accomplish the following:
# a. Print the last 2 columns of the matrix
# b. Print the first 2 rows of the matrix
# c. Replace its elements in the central  matrix by the maximum value present there, and print the updated matrix. [Note that the maximum element value in an NumPy array can be determined by using numpy.max() method]

import numpy as np

# User input
# arr = np.empty([4,4])

# for row in range(4):
#     for col in range(4):
#         x = input("Enter element: ")
#         arr[row][col] = x

# Manual input
arr = np.resize([1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16], (4,4))

print(arr)
print(arr[:,-2:])
print(arr[:2,:])
max_val = np.max(arr[1:3,1:3])

arr[1:3, 1:3] = max_val
print(arr)