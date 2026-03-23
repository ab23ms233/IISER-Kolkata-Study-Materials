
import math

#Q1



#Q2

    

#Q3



#Q4



#Q5



#Q6

        

#Q7



#Q8



#Q9



#Q10


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
            