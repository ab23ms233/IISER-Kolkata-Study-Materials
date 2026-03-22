n = int(input("Enter number: "))

for row in range(n):
    for col in range(n-row):
        if col%2 == 0:
            print(f"{row} ", end = ' ')
        else:
            print("# ", end = ' ')
    print()