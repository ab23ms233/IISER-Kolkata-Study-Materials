#SET 2

import math

s = 0
n = 1
x = 3*math.pi/2
t = x
numerator = x
denominator = 1
actual = math.sin(x)

f = open("Sine.txt", 'w')
g = open("Sine.dat", 'w')

while abs(s - actual) > 1e-4:
	s += t
	rounded = round(s, 3)
	f.write(str(n) + " " + str(rounded) + "\n")
	g.write(str(n) + " " + str(rounded) + " " + str(actual) + "\n") 
	numerator *= -(x**2)
	denominator *= (n+1)*(n+2)
	n+=2
	t = numerator/denominator
  	
print(s)

f.close()
g.close()

    
