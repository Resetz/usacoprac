def solve():
    n = int(input(""))
    arr = [int(x) for x in input("").strip().split(" ")]

    ans = arr[-1] - arr[0]
    ans = max(ans, max(arr) - arr[0])
    ans = max(ans, arr[-1] - min(arr))

    for x in range(1, n):
        ans = max(ans, arr[x-1]-arr[x])
    
    print(ans)

n = int(input(""))
while ( n > 0 ):
    solve()
    n-=1