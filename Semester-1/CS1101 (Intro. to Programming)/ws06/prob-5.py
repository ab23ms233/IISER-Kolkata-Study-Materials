import math

def f(x,n):
    s,denominator,sign = 0,1,0
    
    for i in range(n):
        s+=(-1)**sign*(x**denominator)/denominator
        denominator+=2
        sign+=1
    
    return 4*s

count=0
function_pi = f(1,count)

while round(abs(function_pi-math.pi),2)!=0:
    count+=1
    function_pi = f(1,count)
    print(f"{count}      {function_pi}      {math.pi}")
    