num = int(input("Enter a number: "))
i = 2
if num==1:
    print("Number is neither prime nor composite")
else:
    while i<=num**0.5:
        if num%i==0:
            print(num,"is not a prime number")
            break
        i+=1
    else:
            print(num,"is a prime number")