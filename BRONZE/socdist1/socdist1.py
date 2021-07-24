"""
ID: vincent97
LANG: PYTHON3
TASK: socdist1
"""
inf = 2000000
def get_patch_end(a):
    return a[0] + a[1]

def get_patch_begin(a):
    return a[0]

def ok(a, patches):
    current_index = 0
    current_patch = 0
    index_values = []
    if a * cows > get_patch_end(patches[-1]):
        return -1
    for i in range(cows):
        if current_index > get_patch_end(patches[-1]):
            #print("Current_index exceeded.", current_index, get_patch_end(patches[-1]))
            #print(index_values)
            #print(int(current_index))
            return -1
        if current_index > get_patch_end(patches[current_patch]):
            if current_patch+1 < len(patches):
                #if current_index > patches[current_patch+1][0]

                if current_index <= patches[current_patch+1][0]:
                    current_index = patches[current_patch+1][0]
                    current_patch += 1
                    continue

                else:
                    ow_count = 0
                    for x in range(current_patch+1, N):
                        if current_index > patches[x][0]:
                            ow_count+=1
                            current_index = patches[x][0]
                            current_patch = x
                            break
                    continue
            else:
                return -1
        if i == cows - 1 and current_index < get_patch_end(patches[-1]):
            return -2
        current_index += a
    return 1


fin = open ('socdist1.in', 'r')
fout = open ('socdist1.out', 'w')

patches = []
cows, N = [int(n.strip()) for n in fin.readline().split(" ")]
print(cows, N)
for _ in range(N):
    patches.append(fin.readline().split(" "))
    patches[-1] = [int(n) for n in patches[-1]]
    patches[-1][1] = patches[-1][1] - patches[-1][0]

patches = sorted(patches, key=get_patch_begin)

current = N
increase = N/2
prev_result = False
next_result = True

ans = 0
print(ok(3,patches))
while True:
    result = ok(current, patches)
    if result == 1 or result == -2:
        print(result)
        if current > ans:
            ans = current
        current += increase
    else:
        current -= increase
    if increase < 1:
        break
    
    increase /= 2
    if ((increase - 0.5) % 2 == 1):
        increase += 0.5
    increase = int(increase)
    print(increase, current)


print(ans)
    
    