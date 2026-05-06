"""Define a function to calculate the quotient
 and remainder of 2 numbers: x,y"""
 
def f(a,b):
     #q stores quotient of a/b
     q = a//b
     
     #r stores remainder of x/2
     r = a%b
     return q,r

#User Input
x = int(input("Enter the dividend: "))
y = int(input("Enter the divisor: ")) 

#c,d stores values returned by the function
c,d = f(x,y)
print(f"Quotient is {c} and remainder is {d}")