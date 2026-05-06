import math

#Function to calculate arctan series
def f(x,n):
    s,denominator,sign = 0,1,0
    
    for i in range(n):
        s+=(-1)**sign*(x**denominator)/denominator
        denominator+=2
        sign+=1
    
    return 4*s

count = 1
function_pi = f(1,count)

#Calculating the absolute difference upto 3 decimal places
while round(abs(function_pi-math.pi),3)!=0:
    print(function_pi, math.pi)
    print(round(abs(function_pi-math.pi),3))
    count+=1
    function_pi = f(1,count)
    
print(f"Calculated value of pi is {function_pi}")
print(f"Actual value of pi is {math.pi}")
print(f"Number of terms required is {count}")
print(f"Difference is {abs(math.pi-function_pi)}")
