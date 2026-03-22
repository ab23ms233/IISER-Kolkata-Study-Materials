num_list = [2,3,4,5,6]

def gcd(num_1, num_2):
    large, small = max(num_1, num_2), min(num_1, num_2)
    
    if large%small == 0:
        return small
    
    large, small = small, large%small
    return gcd(large, small)

def lcm(num_1, num_2):
    return num_1*num_2/gcd(num_1, num_2)

req = lcm(num_list[0], num_list[1])

for i in range(2, len(num_list)):
    req = lcm(req, num_list[i])

print(req)


    
    
    