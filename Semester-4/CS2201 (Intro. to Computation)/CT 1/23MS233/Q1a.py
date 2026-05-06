import math

#Defining the start, stop and step values
start = 3
stop = 4
step = 0.1

#Initiating x_val = start
x_val = start

#Defining the function given 
def f(x):
    return (math.e**(-x))*(3.2*math.sin(x) - 0.5*math.cos(x))

#Running the loop to check when (f(x)*f(x+step) < 0) --> Root lies in between x and x+step
while x_val <= stop:
    y_val1 = f(x_val)
    y_val2 = f(x_val+step)
    
    #Checking the condition for root lying in between
    if y_val1*y_val2 < 0:
        print(f"Required Interval: [{x_val}, {x_val+step}]")
        break
    
    #Incrementing x_val by step
    x_val += step
    

    