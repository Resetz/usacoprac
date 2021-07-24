n = input("")
cows = [int(n)%2 for n in input("").strip().split(" ")]

even_group = True

num_of_one = 0
num_of_two = 0
groups = 0
group_cows = []
for x in cows:
    if x == 0:
        num_of_one += 1
    else:
        num_of_two += 1
while True:
    if even_group:
        even_group = not even_group

        if num_of_one > 0:
            num_of_one -= 1
            groups += 1
            group_cows.append([1])
            continue
        elif num_of_two > 1:
            num_of_two -= 2
            groups += 1
            group_cows.append([2,2])
            continue
        else:
            break
    else:
        even_group = not even_group

        if num_of_two > 0:
            num_of_two -= 1
            group_cows.append([2])
            groups += 1
        else:
            break
if num_of_two + num_of_one == 0:
    pass
elif even_group:
    pass
else:
    if num_of_two == 1:
        groups -= 1  
    
    
print(groups)