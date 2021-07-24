import math
num = int(input())
N = int(input())
nums = []
for _ in range(N):
    nums.append(int(input("")))

nums = sorted(nums)

start = 0
end = N-1
mid = 0
loops = 1
solution = -1
while start < end:
    mid = int((start + end)/2)
    
    if end - start == 1 :
        if nums[end] == num:
            solution = end
            break
        if nums[start] == num:
            solution = start
            break
        else:
          solution = -1
          break
    if nums[mid] < num:
        start = mid
    elif nums[mid] > num:
        end = mid
    else:
        solution = mid
        break
    loops += 1
    print(start, end)
print(solution)
print(loops)


