#Taking list input from user
l = eval(input("Enter a list of numbers: "))
s = 0

#Checking if the total of 2 numbers of the list is equal to s and the 2 numbers are not equal
for i in range(len(l)):
    for j in range(i, len(l)):
        
        if (l[i] + l[j] == s) and (l[i] != l[j]):
            print(f"{i}, {j}")