# QUESTION
# Write a program which prints the following sequence of strings using a for loop
# mitochondria
# mitochondria
# mitochondri
# mitochondr
# mitochond
# mitochon
# mitocho
# mitoch
# mitoc
# mito
# mit
# mi
# m

s = "mitochondria"

for i in range(len(s), 0, -1):
    print(s[:i])