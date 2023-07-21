infile = open("revegetate.in", "r")
outfile = open("revegetate.out", "w")

pastures,ncows = [int(x) for x in (infile.readline().strip().split(" "))]

cows = []
available = [[True, True, True, True] for _ in range(pastures)]

for x in range(ncows):
    a, b = [(int(x)-1) for x in infile.readline().split(" ")]
    if (a > b):
        a, b = b, a
    cows.append([a, b])

cows = sorted(cows)

counter = 0

for x in range(pastures):
    seed = 0
    for y in range(4):
        if (available[x][y]):
            seed = y
            break

    while (counter < ncows and cows[counter][0] == x):
        available[cows[counter][1]][seed] = False
        counter+=1

    outfile.write(str(seed+1))

outfile.close()
infile.close()


