"""Define a function to take 3 lenghts from user and 
check whether they form a triangle or not"""

#User Input
a = int(input("Enter first side: "))
b = int(input("Enter second side: "))
c = int(input("Enter third side: "))

def triangle(x,y,z):
    
    #Checking whether sum of 2 sides is greater than third side
    if x+y>z and y+z>x and z+x>y:
        return True
    else:
        return False

print(triangle(a, b, c))