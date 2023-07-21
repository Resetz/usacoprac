t = int(input(""))
for _ in range(t):
    total = 0
    n = int(input(""))
    time = input("")
    for x in range(n):
        if int(time[x]) == 0:
            continue
        if x == n-1:
            total += int(time[x])
        else:
            total += int(time[x]) + 1
    print(total)