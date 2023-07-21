
def solve():
    n = input()
    p = [input().strip().split("") for _ in range(n)]
    
    m = input()
    s = [input().strip().split("") for _ in range(m)]

    good = []
    for _ in range(n):
        good.append([0 for _ in range(p)])
    
    for _ in range(4):
        for x in range(n-s+1):
            for y in range(n-s+1):
                canstamp = True
                for i in range(s):
                    for j in range(s):
                        if (s[i][j] != p[x+i][y+j]):
                            canstamp = False
                
                if (canstamp):
                    for i in range(s):
                        for j in range(s):
                            if (s[i][j]):
                                good[x+i][y+j] += 1
        
        #perform rotation
        temp = []
        for _ in range(s):
            temp.append(['.' for _ in range(s)])
        for i in range(s):
            for j in range(s):
                if (s[i][j] == "*"):
                    temp[j][(m-1)-j] = '*'
        s = temp
    
    ans = True
    for x in range(n):
        for y in range(n):
            if (good[x][y] != p[x][y]):
                ans = False
    if (ans):
        print("YES")
    else:
        print("NO")

t = input()
while (t > 0):
    t -= 1
    solve()