import math

#Function to calculate natural logarithmic series
def f(x,n):
    s,sign,power=0,0,1
    
    for i in range(n):
        s+=(-1)**sign*(x**power)/power
        power+=1
        sign+=1
    
    return s
    
count=1
function_ln = f(-0.25, count)

#Calculating the absolute difference upto 6 decimal places
while round(abs(function_ln-math.log(0.75)),6)!=0:
    print(function_ln, math.log(0.75))
    print(round(abs(function_ln-math.log(0.75)),6))
    count+=1
    function_ln = f(-0.25, count)
    
print(f"Computed value of ln(0.75) is {function_ln}")
print((f"Actual value of ln(0.75) is {math.log(0.75)}"))
print(f"Number of terms is {count}")
print(f"Difference is {function_ln-math.log(0.75)}")
    
