n = int(input("Enter the number of terms: "))
perfect = open("perfect.txt",'w')
count,i = 0,2

def divisor_sum(num):
    divisors = [1]
    end,i = num,2

    while i<end:
        if num%i==0:
            if i!=num/i:
                divisors.extend([i,num/i])
            else:
                divisors.append(i)
            end = num/i
        i+=1

    return sum(divisors)

while count<n:
    total = divisor_sum(i)
    if total==i:
        count+=1
        perfect.write(f"{count}   {i}\n")

    i+=1

perfect.close()
