"""Define a function that takes input x from user and 
calculates x//2 and x%2 and prints output"""

def f(x):
    #q stores quotient of x/2
    q = x//2
    
    #r stores remainder of x/2
    r = x%2
    return q,r

#User input
s = int(input("Enter a number: "))

#a,b stores values returned by the function
a,b = f(s)
print(a,b)
