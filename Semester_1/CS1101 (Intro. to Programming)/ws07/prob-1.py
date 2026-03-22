n = int(input("Enter the number of terms: "))
fibonacci = open("fibonacci.txt",'w')

a,b = 1,1
for i in range(n):
    fibonacci.write(str(a)+'\n')
    a,b = b,a+b

fibonacci.close()