def f(x):

	#Quotient
	q = x//4
	
	#Remainder
	r = x%4
	
	#Printing the stored values
	print(f"Quotient: {q}; Remainder: {r}")
	
	#Returning the stored values
	return f"Quotient: {q}; Remainder: {r}"
	
num = int(input("Enter a number: "))

print(f(num))
