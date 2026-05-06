cube_sum = 0
armstrong = []

for i in range(1, 1001):
	
	#Remainder on dividing by 10 is the digits of the number
	num = i
	rem = num%10
	
	#When remainder == 0, no digits are left
	while rem > 0:
	
		#Adding cube of the digits
		cube_sum = cube_sum + rem**3
		
		#num is the number excluding the last digit
		num = num//10
		
		#rem is the last digit of new number
		rem = num%10
	
	#If sum of cubes of digits == number, it is an armstrong number
	if cube_sum == i:
		armstrong.append(i)
	
	#Initialising cube_sum = 0
	cube_sum = 0

print("Armstrong numbers are",armstrong)
