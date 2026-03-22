from math import sin, pi

# Function
def fn(x, omega):
    return sin(2*pi*omega*x)

# Parameters
start, end = -20, 20
N = 200
inc = (end-start)/(N-1)
x = start

# sin(2pix) completes 1 cycle as x goes from 0 to 1. If -20 >= x >= 20,
# then it completes 40 cycles. So omega = 1/10 = 0.1 to restrict it to 4 cycles. 
omega = 0.1

f = open("Sin.txt", 'w')

# Calculating and recording f(x)
while x<=end:
    val = fn(x, omega)
    f.write(f"{x} {val}\n")
    x += inc

f.close()


