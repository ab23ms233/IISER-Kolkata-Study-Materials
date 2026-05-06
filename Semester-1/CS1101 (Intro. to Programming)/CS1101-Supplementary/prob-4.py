def isTriangle(a, b, c):
	
	#Checks whether sum of any 2 sides is greater than the 3rd side
	if a+b>c and b+c>a and c+a>b:
		return True
	
	#If above condition is not satisfied, returns False
	return False

num_1 = int(input("Enter 1st number: "))
num_2 = int(input("Enter 2nd number: "))
num_3 = int(input("Enter 3rd number: "))

if isTriangle(num_1, num_2, num_3):
	print("Triangle can be formed with", [num_1, num_2, num_3])
else:
	print("Triangle cannot be formed with", [num_1, num_2, num_3])
