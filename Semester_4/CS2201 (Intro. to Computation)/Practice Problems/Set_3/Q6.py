# QUESTION
# Use a while loop to take a number as input from the user and continue the loop until the user inputs an even number.

while True:
    num = int(input("Enter a number: "))
    
    if num%2 == 0:
        break