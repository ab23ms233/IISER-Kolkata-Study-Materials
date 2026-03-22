#Importimg necessary libraries
import numpy as np
import random

#Setting up variables
#Marks of all students in courses are in between upper and lower 
upper, lower = 40, 100
no_of_students = 5

#Making the required numpy arrays with random
phy = np.array([random.randint(upper, lower) for i in range(no_of_students)])
chem = np.array([random.randint(upper, lower) for i in range(no_of_students)])
bio = np.array([random.randint(upper, lower) for i in range(no_of_students)])

#Printing the arrays
print("Physics:",phy)
print("Chemistry:", chem)
print("Biology:", bio)
print()

#Updating the arrays to add +2 grace marks in PHY and +1 in BIO
phy = np.add(phy, 2)
bio = np.add(bio, 1)

#Printing Updated numpy arrays
print("Updated Physics:", phy)
print("Updated Biology", bio)
print()

#Totalling the marks of all students in all courses
tot = np.empty(no_of_students)

for i in range(no_of_students):
    total = phy[i] + chem[i] + bio[i]
    tot[i] = total

print("Total marks:", tot)
