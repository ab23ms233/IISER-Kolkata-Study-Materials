# QUESTION
# Write a Python program to determine the direction (‘increasing’ or ‘decreasing’ or ‘not monotonic’) of monotonic sequence (consistently increasing or consistently decreasing) numbers stored as a list. E.g. [1, 2, 3, 4, 5, 6] contains a monotonically increasing sequence, while [25, 24, 23, 22] contains a monotonically decreasing sequence; [25, 24, 10, 23, 22] is not monotonic.

# User input
l = eval(input("Enter list: "))
direction = ''

# Checking the direction of the sequence
if l[0]>l[1]:
    direction = "dec"
else:
    direction = "inc"

# Confirming the direction of the sequence
for i in range(1, len(l)-1):
    if (direction == "inc" and l[i] > l[i+1]) or (direction == "dec" and l[i] < l[i+1]):
        print("Not monotonic")
        break

# If loop terminated without break, then the sequence is monotonic
if i == len(l) - 1:
    if direction == "inc":
        print("Increasing")
    else:
        print("Decreasing")