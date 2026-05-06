#Inputing Variables
num_1 = int(input("Enter 1st number: "))
num_2 = int(input("Enter 2nd number: "))
prime = []

#Defining the smallest and Largest numbers
start = min(num_1, num_2)
end = max(num_1, num_2)+1

#Checking prime numbers
for num in range(start, end):
    
    if round(num**(1/2))<num**(1/2):
        last = round(num**(1/2))+2
    else:
        last = round(num**(1/2))+1
        
    for divisor in range(2,last):
        if num%divisor==0:
            break
    else:
        prime.append(num)

#Removing 1 from prime list
if 1 in prime:
    prime.remove(1)
if prime == []:
    print("There are no prime numbers")
else:
    print(prime)