# QUESTION
# Print the pattern using nested for loops (for n lines):

# 1
# 1 3
# 1 3 5
# 1 3 5 7
# 1 3 5 7 9

for i in range(1, 6):
    for j in range(1, 2*i+1, 2):
        print(j, end=" ")
    print()