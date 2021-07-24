def print_arr(a):
    combined = a
    first = True
    for x in range(len(combined)):
        if first:
            print(combined[x], end = ", ")
            first = False
        else:
            if (x == len(combined)-1):
                print(combined[x], end = "")
                continue
            print(str(combined[x]) + ", ", end = "")
    print("")

arr = [ int(x) for x in input("").split(", ")]
original = arr
sorted_arr = []
swaps = 1
print_arr(arr)
for x in range(len(arr)):
    minimum = 100000
    index = 0
    for j in range(x,len(arr)):
        if arr[j] <= minimum:
            #print(arr[j], "<", minimum)
            minimum = arr[j]
            index = j
    prev = arr.copy()
    #print(x,index)
    arr[index], arr[x] = arr[x], arr[index]
    same = True
    for x in range(len(arr)):
        if arr[x] != prev[x]:
            same = False
            break
    if not same:
      swaps += 1
      print_arr(arr)
    
print(swaps, end="")