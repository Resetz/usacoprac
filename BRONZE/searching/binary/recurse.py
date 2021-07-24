import math
num = int(input())
N = int(input())
nums = []
for _ in range(N):
    nums.append(int(input("")))

nums = sorted(nums)
iterations = 0
def binary(start, end):
    global iterations
    iterations += 1
    mid = int((end - start)/2)+start
    if nums[mid] == num:
        return mid
    if end - start == 1:
        if nums[start] == num:
            iterations -= 1
            return start
        if nums[end] == num:
            iterations -= 1
            return end
        else:
            iterations -= 1
            return -1 
    elif num > nums[start]:
        return binary(mid, end)
    elif num < nums[end]:
        return binary(start, mid)
    else:
        return mid

print(binary(0, N-1))
print(iterations)




