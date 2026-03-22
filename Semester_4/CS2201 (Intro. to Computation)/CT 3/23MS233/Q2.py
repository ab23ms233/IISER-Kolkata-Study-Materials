n = int(input("Enter number: "))

#Checking for single digit number
if n//10 == 0:
    sq = n**2
    
    #Last digit of square of n
    rem = sq%10
    
    #Checking if last digit is equal to n
    if rem == n:
        print(f"TRUE: {n} is a single digit Automorphic Number")
    else:
        print(f"FALSE: {n} is not a single digit Automorphic Number")
 
else:
    print(f"{n} is not a single digit number")
