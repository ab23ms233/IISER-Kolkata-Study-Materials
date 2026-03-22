"""import math

increment = 40/199

def f(x):
    return math.sin(2*math.pi*x)

10 """

def hcf(num_1, num_2):
    
    if num_1%num_2 == 0:
        return num_2
    
    return hcf(num_2, num_1%num_2)

num = int(input("Enter number of elements: "))
l = []
co_prime = []

for i in range(num):
    element = int(input("Enter number: "))
    l.append(element)

for i in l:
    for j in l:
        large = max(i, j)
        small = min(i, j)
        
        if hcf(large, small) == 1 and (large, small) not in co_prime:
            co_prime.append((large, small))

for k in co_prime:
    print(k)