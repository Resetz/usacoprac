n = int(input(""))

connections = []
totals = [0 for x in range(n)]
virus = []
for x in range(n):
    connections.append([0 for x in range(n)])
    virus.append([0 for x in range(n)])

for x in range(n-1):
    data = input("").strip().split(" ")

    connections[data[0]][data[1]] = 1
    connections[data[1]][data[0]] = 1
    totals[data[0]] += 1
    totals[data[1]] += 1

cow = max(totals)

while True:
    for x in range(totals):
        pass