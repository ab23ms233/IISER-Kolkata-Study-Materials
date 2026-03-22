f = open("Exponential.txt", 'w')

import math

x = 1
num_of_terms = 1
sign = 1
denominator = 1
numerator = x
computed_pi = 0

while round(abs(4*computed_pi-math.pi), 2) != 0:
    term = sign*numerator/denominator
    computed_pi = computed_pi + term
    
    denominator += 2
    numerator = numerator*x**2
    sign *= -1
    num_of_terms += 1
    
    f.write(str(num_of_terms) + ' ' + str(4*computed_pi) + ' ' + str(math.pi) + '\n')

f.close()