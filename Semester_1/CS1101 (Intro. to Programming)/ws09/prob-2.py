from math import exp

# f(x)
def fn(x, sigma):
    return exp(-x**2/sigma)

# Parameters
start, end = -5, 5
x = start
N = 100
sigma = 4
inc = (end - start)/(N-1)

# Lists for storing data
values, points = [], []
req_points = []
req_values = []

# Calculating f(x) for different x
while round(x, 2) <= end:
    value = fn(x, sigma)
    points.append(x)
    values.append(value)
    x += inc

# Finding f_max
maximum = values[0]
for value in values:
    if maximum < value:
        maximum = value

# Finding x for which f(x) = f_max
for j in range(len(values)):
    if abs(values[j] - maximum/2)<0.01:
        req_points.append(points[j])
        req_values.append(values[j])
        
print(req_points)

# Storing data in a file
f = open("Exp.dat", 'w')
for i in range(len(values)):
    f.write(str(points[i])+" "+str(values[i])+'\n')

f.close()

# Storing points for which f(x) = f_max
g = open("Special_Points.dat", 'w')
for j in range(len(req_values)):
    g.write(str(req_points[j])+" "+str(req_values[j])+'\n')

g.close()