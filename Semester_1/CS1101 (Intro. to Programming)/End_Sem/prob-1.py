import math

#Opening file to store values
f = open("Cos.dat",'w')

#Defining start, end values and step size
start = -math.pi/4
end = 3*math.pi/4
increment = (end-start)/1000

#Defining x, max and min values of x and f(x)
x = start
f_max, x_max = -2,-2
f_min, x_min = 2, 2


for i in range(1000):

	#Calculating each term
	term = (math.cos(x))**2
	
	#Setting f_max, x_max
	if term > f_max:
		f_max = term
		x_max = x
	
	#Setting f_min, x_min
	if term < f_min:
		f_min = term
		x_min = x
	
	#Writing in file
	f.write(str(x) + " " + str(term) + '\n')
	
	#Incrementing x value 
	x += increment

#Closing file
f.close()

#Printing max and min values of x and f(x)
print(f"Maximum value of function: {f_max} and x-value: {x_max}")
print(f"Minimum value of function: {f_min} and x-value: {x_min}")
	
	
