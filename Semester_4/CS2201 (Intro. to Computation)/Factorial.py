def factorial(x):
    if x == 1:
        return 1
    return x*factorial(x-1)

file = open("Factorial.txt", 'w')

for i in range(1, 6):
    fact = factorial(i)
    file.write(str(i) + " " + str(fact) + '\n')

file.close()