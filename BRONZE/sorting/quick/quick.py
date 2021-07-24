def swap(a, b):
    global arr
    arr[a], arr[b] = arr[b], arr[a]



def partition(a, b):
    global arr
    start = a - 1
    end = b

    pivot = arr[b]

    while (True):
        while (True):
            start += 1
            if (arr[start] >= pivot):
                break
        

        finish = False
        while (True):
            end -= 1
            if (end < 0):
                finish = True
                break
            if (arr[end] <= pivot):
                break


        if (finish):
            break
        
        if (end < start):
            break
        #print(start, end)
        swap(end, start)
        

    swap(b, end)
    return end


def quicksort(a, b):
    if (b > a and a >= 0 and b >= 0):
        global arr
        global ans

        pi = partition(a, b)
        
        #print(a, b, pi)
        ans.append(arr[pi])
        if (pi != 0):
            quicksort(a, pi-1)
        if (pi != len(arr) - 1):
            quicksort(pi+1, b)
        else:
            quicksort(pi, b)
    return





arr = []
ans = []
n = int(input(""))

for _ in range(n):
    arr.append(int(input("")))

quicksort(0, len(arr)-1)

print(len(ans))
for x in ans:
    print(x)