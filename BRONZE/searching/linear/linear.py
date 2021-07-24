import math
N = int(input(""))
nums = []
for _ in range(N):
    nums.append(int(input("")))

nums = sorted(nums)
sol = []
for x in range(N):
    closest_square = int(math.sqrt(nums[x]*2))
    if closest_square * (closest_square + 1) == nums[x]*2:
        sol.append(closest_square+1)

print(len(sol))

for x in sol:
    print(x,nums[x])


