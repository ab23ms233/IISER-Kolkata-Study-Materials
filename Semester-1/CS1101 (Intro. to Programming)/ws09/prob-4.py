# Parameters
term_1 = 1
term_2 = 1
phi = 1
count = 1

fib = open("fib_inverse.txt", 'w')

# Generating and storing data in a file
while round(abs(phi-3.359885), 6) != 0:

    reciprocal = 1/term_2
    phi += reciprocal
    fib.write(str(count) + " " + str(phi) + '\n')
    
    count += 1
    term_1, term_2 = term_2, term_1+term_2
    
print(count)
fib.close()