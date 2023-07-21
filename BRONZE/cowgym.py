infile = open("gymnastics.in","r")
outfile = open("gymnastics.out","w")

n,m = [int(x) for x in infile.readline().split(" ")]

cows = []

for x in range(n):
    for y in range(m):
        cows.append([int(x)-1 for x in infile.readline().split()])

ans = 0
for a in range(m):
    for b in range(a+1, m):

        first = -1
        good = True
        for y in range(m):
            if (cows[0][y] == a or cows[0][y] == b):
                first = cows[0][y]
                break

        for x in range(1,n):

            for y in range(m):
                if (cows[x][y] == a or cows[x][y] == b):
                    if (cows[x][y] != first):
                        good = False
                    break
                
            if (not good):
                break
        if (good):
            print(a+1, b+1)
            ans+=1

outfile.write(str(ans))

