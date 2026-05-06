# QUESTION
# Use numpy array to generate the following pattern for n (taken from user) lines (shown for n = 4):
# 1.0

# 1.0 1.5 2.0

# 1.0 1.5 2.0 2.5 3.0

# 1.0 1.5 2.0 2.5 3.0 3.5 4.0

import numpy as np

n = int(input("Enter number of rows: "))
arr = np.arange(1, n+0.1, 0.5)

for row in range(n):
    for col in range(2*row+1):
        print(str(arr[col]), end = " ")
    print()