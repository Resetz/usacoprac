infile = open("factory.in","r")
outfile = open("factory.out","w")

n = int(infile.readline().strip())

adj = [-1] * n
for _ in range(n-1):
    f,t = [int(x) for x in infile.readline().strip().split(" ")]
    f-=1
    t-=1
    adj[f] = t


def canReach(k, target):
    if (k == target): return True
    if (k == -1): return False
    return canReach(adj[k], target)

for x in range(n):
    good = True
    for y in range(n):
        if (not canReach(y, x)):
            good = False
            break
    
    if (good):
        outfile.write(str(x+1))
        exit()

outfile.write(str(-1))
