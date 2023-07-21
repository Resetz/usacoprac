
def getKey(x):
    return x[0]


infile = open("measurement.in","r")
outfile = open("measurement.out","w")

cows = [7,7,7]
n = int(infile.readline())

times = []

for x in range(n):
    line = infile.readline().split(" ")
    a = int(line[0])
    c = int(line[2])
    b = 0
    if (line[1] == "Bessie"): 
        b = 0
    elif (line[1] == "Elsie"): 
        b = 1
    else:
        b = 2
    times.append([a,b,c])

times = sorted(times, key=getKey)


prev = set()
prev.add(0)
prev.add(1)
prev.add(2)


ans = 0
for x in times:
    cows[x[1]] += x[2]

    curmax = -1000000
    cur = set()
    for y in range(3):
        if (cows[y] >= curmax):

            if (cows[y] > curmax):
                cur.clear()
            cur.add(y)

            curmax = cows[y]
    
    if (prev != cur):
        ans+=1
    prev = cur

outfile.write(str(ans))

