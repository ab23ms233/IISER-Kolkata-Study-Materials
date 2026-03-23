# QUESTION
# Use list comprehension to create a list containing all the elements in list L1 and not in L2

# User input for lists
# L1 = eval(input("Enter list 1: "))
# L2 = eval(input("Enter list 2: "))

L1 = [1, 2, 3, 4, 5]
L2 = [4, 5, 6, 7, 8]
L3 = []

for x in L1:
    if x not in L2:
        L3.append(x)
        
print("Elements in L1 but not in L2: ", L3)