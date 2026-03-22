#Q1
'''l = eval(input("Enter a list: "))
d = {}

for i in range(0, len(l), 2):
    d[l[i]] = l[i+1]
    
print(d)

#Q2
new_l = []

for i in range(0, len(l), 2):
    t = (l[i], l[i+1])
    new_l.append(t)

print(new_l)'''

import numpy as np

A = np.resize([i for i in range(1, 17)], (4,4))
print(A)
B = -A
print(B)

for row in range(0, len(A), 2):
    for col in range(0, len(A), 2):
        A[row][col] = B[row][col]

print(A)

A = np.resize([i for i in range(1, 17)], (4,4))
B = np.empty(shape=(4,2,2))

B[0][:2][:2] = np.resize(A[:2, :2], (1,2,2))
B[1][:2][:2] = np.resize(A[:2, 2:], (1,2,2))
B[2][:2][:2] = np.resize(A[2:, :2], (1,2,2))
B[3][:2][:2] = np.resize(A[2:, 2:], (1,2,2))

print(B)