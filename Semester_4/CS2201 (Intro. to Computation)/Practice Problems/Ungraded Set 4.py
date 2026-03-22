import numpy as np
import math

#Q1
L1 = eval(input("Enter list 1: "))
L2 = eval(input("Enter list 2: "))
L3 = []

for x in L1:
    if x not in L2:
        L3.append(x)
        
print("L3: ", L3)


#Q2
n = int(input("Enter number of rows: "))
arr = np.arange(1, n+0.1, 0.5)

for row in range(n):
    for col in range(2*row+1):
        print(str(arr[col]), end = " ")
    print()
    

#Q3
total = ord("a") + ord("z")

def encrypt(s):
    new = ""
    
    for i in s:
        num = ord(i)
        rem = total - num
        element = chr(rem)
        new += element
    
    return new

s = input("Enter string: ")
print(encrypt(s))


#Q4
s = input("Enter string: ")
n = len(s)
new = ""

if len(s)%2 == 0:
    left, right = s[:n//2], s[n//2:]
    new = right + left
else:
    left, right = s[:n//2], s[n//2+1:]
    mid = s[n//2]
    new = right + mid + left

print(new)


#Q5
l = eval(input("Enter list: "))
s = set(l)
new_l = list(s)
print(new_l)


#Q6
arr = np.array([[1,2,3], [4,5,6]])
rows, columns = arr.shape

for row in range(rows):
    for col in range(columns):
        print(arr[row][col])
        

#Q7
def calc_area(r):
    return math.pi*r**2

radius_list = eval(input("Enter radii: "))
area_list = []

for r in radius_list:
    area = calc_area(int(r))
    area_list.append(area)

print(area_list)


#Q8
area_np = np.empty((1,5))
radius_np = np.random.randint(0, 10, size=(1,5))
print(radius_np)

for r in radius_np:
    area = calc_area(r)
    area_np = np.resize(np.array(area), (1,5))
    np.append(area_np, area_np, axis=0)
    
print(area_np)


#Q9
d = {}

for i in range(5):
    roll = input("Enter roll: ")
    marks = eval(input("Enter marks in list: "))
    marks_np = np.array(marks, dtype='float64')
    
    d[roll] = marks_np
    
print(d)


#Q10
for i in d:
    total = np.sum(d[i])
    d[i] = total

print(d)

#Q11
l1 = eval(input("Enter list 1: "))
l2 = eval(input("Enter list 2: "))

arr1, arr2 = np.array(l1), np.array(l2)

if len(arr1) == len(arr2):
    for i in range(len(arr1)):
        if arr1[i] != arr2[i]:
            print("The 2 arrays are not equal")
            break
    else:
        print("The 2 arrays are equal")
else:
    print("The 2 arrays are not equal")
    
print(np.array_equal(arr1, arr2))


#Q12
l = [[1, 2, 3, 4, 11], [100, 55, 80, 33, 22]] 
arr = np.array(l)

print(arr)
print(arr[:,3:])
            