from math import exp, pi

# Parameters
t = 1
count = 1
s = 1

# Checking for accuracy upto 10^(-4)
while abs(s-exp(pi)) > 1e-4:
    t = pi/count*t
    count+=1
    s+=t
    print(s)
    
print("Difference is:", abs(s - exp(pi)))
print("Number of terms required is:", count)
