# QUESTION
# Create two 2-D NumPy arrays or matrices, namely A and B, of dimension  each. Use array slicing to replace every second element starting from index 0 along the rows and the columns of matrix A with the corresponding element in matrix B. Now, print the updated matrix A.

import numpy as np

# Making given arrays
# A = [1, 2, 3, 4
#      5, 6, 7, 8
#      9, 10, 11, 12
#      13, 14, 15, 16]
# B = -A
arr_A = np.resize([i for i in range(1,17)], (4,4))
arr_B = np.resize([i for i in range(-1, -17, -1)], (4,4))

# Exchanging
arr_A[::2,::2] = arr_B[::2, ::2]
print(arr_A)