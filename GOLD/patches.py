def solve():
    n, k = [int(i) for i in input().strip().split()]

    cows = input()

    g = []
    h = []
    for x in range(n):
        if (cows[x] == "G"):
            g.append(x)
        else:
            h.append(x)

    g.append(10000000)  #end of the array
    h.append(10000000)

    curg = 0
    curh = 0

    ans = ['.'] * n
    total = 0
    while True:
        if (g[curg] < h[curh]):
            #find position that will satisfy both
            nxt = curg
            while (nxt+1 < (len(g)-1) and g[nxt+1] - g[curg] <= k * 2):
                nxt += 1

            #find the middle
            mid = (g[curg] + g[nxt]+1) // 2
            if (ans[mid] != '.'):
                mid -= 1
            ans[mid] = 'G'
            total+=1

            curg = nxt+1
        elif (h[curh] < g[curg]):
            #find position that will satisfy both
            nxt = curh
            while (nxt+1 < (len(h)-1) and h[nxt+1] - h[curh] <= k * 2):
                nxt += 1

            #find the middle
            mid = (h[curh] + h[nxt]+1) // 2
            #print(nxt, curh, len(h),mid)
            if (ans[mid] != '.'):
                mid -= 1
            ans[mid] = 'H'
            total+=1

            curh = nxt+1
        else:
            break
    print(total) 
    for x in ans:
        print(x, end="")
    print()


n = int(input())
for _ in range(n):
    solve()
