import math

x = int(input("Enter number: "))
num = int(input("Enter number of terms: "))

numerator = x
denominator = 1
sign = 1
computed_ln = 0
count = 0

while round(abs(computed_ln - math.log(0.75, math.e)), 6) != 0:
    term = sign*numerator/denominator
    computed_ln = computed_ln + term
    
    numerator = numerator*x
    sign *= 1
    denominator += 1
    count += 1

print("Number of terms:", count)
print()

s = 0
numerator = x
denominator = 1
sign = 1

def tan_inverse(x, n):
    global s,numerator,denominator,sign
    
    if n == 1:
        return s
    
    term = sign*numerator/denominator
    s = s + term
    
    numerator *= x**2
    sign *= 1
    denominator += 2

count = 1
arc_tan = tan_inverse(1, count)

while round(abs(arc_tan - math.pi), 3) != 0:
    count += 1
    arc_tan = tan_inverse(1, count)
