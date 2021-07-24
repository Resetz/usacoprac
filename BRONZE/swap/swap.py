"""
ID: vincent97
LANG: PYTHON3
TASK: swap
"""

fin = open ('swap.in', 'r')
fout = open ('swap.out', 'w')

n, m, k = [int(x) for x in fin.readline().strip().split(" ")]
print(n,m,k)
swaps = []
for _ in range(m):
    swaps.append([int(x) - 1 for x in fin.readline().strip().split(" ")])

cows = [x for x in range(n)]

print(swaps)
print(cows)

flipped_cows = [0 for x in range(n)]
for x in range(len(cows)):
    for y in swaps:
        if (x >= y[0] and x <= y[1]):
            pass

#flip_array = [x for x in range(n)]
#for swap in swaps:
#    for x in range(swap[0], swap[1]+1):
#        if (swap[1]-(x-swap[0])) - x < 0:
#            break
#        #print(x, swap[1]-(x-swap[0]))
#        flip_array[x], flip_array[swap[1]-(x-swap[0])] = flip_array[swap[1]-(x-swap[0])],  flip_array[x]
#
#print(flip_array)



#loops = []
#already_checked = []
#for x in flip_array:
#    if x in already_checked:
#        continue
#    loop = []
#    index = x
#    while not index in loop:
#        loop.append(index)
#        already_checked.append(index)
#        index = flip_array[index]
#        
#    loops.append(loop)
#
#print(loops)
#new_cows = [0 for x in range(n)]
#index = 0
#for x in cows:
#    for y in loops:
#        if x in y:
#            new_index = y[(y.index(x) + k) % len(y)]
#            new_cows[new_index] = x
#    index += 1



#
#print([x+1 for x in flip_array])
#for x in range(k):
#    new_cows = [x for x in range(n)]
#    print("cows before swap", cows)
#    already_swapped = []
#    for y in range(n):
#        new_cows[flip_array[y]] = cows[y]
#    
#    cows = new_cows
#    print("cows after swap", new_cows)


for x in cows:
    fout.write(str(x+1) + "\n")

