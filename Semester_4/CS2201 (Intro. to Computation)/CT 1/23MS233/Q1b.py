import math

accuracy = int(input("Enter the decimal places of accuracy required (ex; 5): "))
#Defining the function
def f(x):
    return (math.e**(-x))*(3.2*math.sin(x) - 0.5*math.cos(x))

def der_f(x):
    return 2.7*math.e**(-x)*(math.cos(x)-math.sin(x))

#Bisection
def Bisection(a, b):
    global accuracy
    c = (a+b)/2
    
    #if c is the root of f
    if round(f(c), 15) == 0:
        return round(c, accuracy)
    
    #if root lies in between a and c, call Bisection on (a,c)
    elif f(a)*f(c) < 0:
        return Bisection(a, c)
    
    #if root lies in between c and b, call Bisection on (c,b)
    else:
        return Bisection(c, b)

#Finding the root
root_1 = Bisection(3.2, 3.3)
print("Root of the equation is ", root_1)
