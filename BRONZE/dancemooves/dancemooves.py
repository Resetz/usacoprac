def swap_num(x, swap):
    if x == swap[0]:
        return swap[1]
    else:
        return swap[0]

n, k = [int(x) for x in input("").strip().split(" ")]
swaps = []
cows = [x for x in range(n)]
for _ in range(k):
    swaps.append([int(x)-1 for x in input("").strip().split(" ")])

ret = []
for x in range(n):
    start_swap = -1
    index = x
    cur_cow = cows[index]
    
    for y in range(k):
        if cur_cow in swaps[y]:
            start_swap = y
            index = swap_num(x, swaps[y])
            #print("Initial swap:", swaps[y], "| Index now:", index)
            break

    unique_trips = [index, x]
    unique_swaps = [start_swap]
    if start_swap == -1:
        ret.append(1)
        continue

    current_swap = start_swap
    

    while True:
        current_swap += 1
        
        
        if current_swap >= k:
            current_swap = 0
        #print(cur_cow, cows[index], swaps[current_swap], current_swap, unique_trips, unique_swaps)
        if current_swap in unique_swaps and cows[index] in swaps[current_swap]:
            break
        if cows[index] in swaps[current_swap]:
            index = swap_num(index, swaps[current_swap])
            if not current_swap in unique_swaps:
                unique_swaps.append(current_swap)
            if not index in unique_trips:
                unique_trips.append(index)
        
        
        
    
    ret.append(len(unique_trips))
    #print(ret)

for x in ret:
    print(x)



