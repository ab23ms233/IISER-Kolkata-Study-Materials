# QUESTION
# Write a Python function that takes two lists and returns True if they have at least one common member.

def common(l1: list, l2: list):
    set_1 = set(l1)
    set_2 = set(l2)

    common = set_1.intersection(set_2)

    if len(common) >= 1:
        return True
    else:
        return False

l1 = [3, 5, 7, 9]
l2 = [6, 3, 7, 1]
print(common(l1, l2))