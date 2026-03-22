#Inputing Variables
num_1, num_2, num_3 = map(int, input("Enter 3 sides: ").split())

#Checking sum
if num_1==0 or num_2==0 or num_3==0:
    print("No triangle can be formed")
elif num_1+num_2<num_3 or num_2+num_3<num_1 or num_3+num_1<num_2:
    print("No triangle can be formed")
else:
    print("Triangle can be formed")