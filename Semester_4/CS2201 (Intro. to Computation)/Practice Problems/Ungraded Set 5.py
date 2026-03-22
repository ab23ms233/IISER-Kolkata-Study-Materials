import numpy as np

#Q1
'''arr = np.empty(9)

for i in range(9):
    x = input("Enter element: ")
    arr[i] = x

print(arr)
print(arr[::-1])'''

#Q2
'''arr = np.empty(9)

for i in range(9):
    x = input("Enter element: ")
    arr[i] = x

print(arr[-3:])
print(arr[:3])
print(arr[3:6])
print(arr[-5:-1])

for i in range(1,9,2):
    arr[i] = 0

print(arr)'''


#Q3
'''arr = np.empty([4,4])

for row in range(4):
    for col in range(4):
        x = input("Enter element: ")
        arr[row][col] = x'''

arr = np.resize([1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16], (4,4))

print(arr)
print(arr[:,-2:])
print(arr[:2,:])
max_val = np.max(arr[1:3,1:3])

arr[1:3, 1:3] = max_val
print(arr)

#Q4
arr_A = np.resize([i for i in range(1,17)], (4,4))
arr_B = np.resize([i for i in range(-1, -17, -1)], (4,4))

arr_A[::2,::2] = arr_B[::2, ::2]

print(arr_A)

#Q5
arr = np.resize([1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16], (4,4))
arr_B = np.empty((4,2,2))
arr_B[:1,:2,:2] = np.resize(arr[:2,:2], (1,2,2))
arr_B[1:2, :2, :2] = np.resize(arr[:2, 2:], (1,2,2))
arr_B[2:3, :2, :2] = np.resize(arr[2:,:2], (1,2,2))
arr_B[3:,:2,:2] = np.resize(arr[2:,2:], (1,2,2))

print(arr_B)
print(arr_B.shape)

