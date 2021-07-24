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

shifts = 0
for x in range(1, len(arr)):
    current = x
    if arr[current] > arr[x]:
        continue
    print(arr)
    while True:
        if current <= 0:
            break
        if arr[current-1] < arr[current]:
            break
        shifts += 1
        print("swapping", current, "and", current-1, "...", (arr[current-1], arr[current]))
        temp = arr[current]
        arr[current] = arr[current-1]
        arr[current-1] = temp
        print(arr)
        current -= 1
        
        
    
    
    print("--------------------------------")
    #print_arr(arr)
    


#
#sorted_arr = []
#shift = 0
#
#for x in range(len(original)):
#    if len(sorted_arr) == 0:
#        sorted_arr.append(arr[0])
#        arr.pop(0)
#        continue
#    fit = False
#    temp = 0
#    for y in range(len(sorted_arr)):
#        temp += 1
#        #print(sorted_arr[y], original[x])
#        if sorted_arr[y] >= arr[0]:
#            sorted_arr.insert(y, arr[0])
#            arr.pop(0)
#            fit = True
#            break
#    if not fit:
#        sorted_arr.insert(x, arr[0])
#        arr.pop(0)
#    else:
#        shift += temp
#    print_arr(sorted_arr + arr)
#
#    
#    #print(sorted_arr, arr)
##print(shift)