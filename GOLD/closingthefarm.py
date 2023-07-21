class dsu:
    def __init__(self, size: int):
        self.parent = [i for i in range(size)]
        self.sizes = [1 for _ in range(size)]
        self.size = size
    
    def find_parent(self, a: int) -> int:
        if (a == self.parent[a]):
            return a
        self.parent[a] = self.find_parent(self.parent[a])
        return self.parent[a]

    def union_set(self, a: int, b: int):
        a = self.find_parent(a)
        b = self.find_parent(b)
        if (a != b):
            # a is not in the same set as b
            if (self.sizes[a] < self.sizes[b]):
                a,b = b,a
            
            # perform union
            self.parent[b] = a
            self.sizes[a] = self.sizes[b]

            self.size -= 1

fin = open("closing.in", "r")
fout = open("closing.out", "w")

n, m = [int(x) for x in fin.readline().strip().split(" ")]
d = dsu(n)

adj = []
for _ in range(n):
    adj.append([])

for _ in range(m):
    f,t = [int(x)-1 for x in fin.readline().strip().split(" ")]
    adj[f].append(t)
    adj[t].append(f)

order = []
for i in range(n):
    order.append(int(fin.readline().strip())-1)
order = reversed(order)


exists = [False for _ in range(n)]
ans = [False for _ in range(n)]

num = 0 # number of nodes placed
for i in order:

    num += 1
    exists[i] = True

    for x in adj[i]:
        # check if the other node exists
        # if it does exist => add the edge
        if (exists[x]):
            d.union_set(i, x)
    
    # n - num => position in ans array
    # d.size - (n-num) => need to subtract out nodes that don't exist.
    ans[n-num] = (d.size - (n-num) == 1)

for i in ans:
    if (i):
        fout.write("YES\n")
    else:
        fout.write("NO\n")
