from itertools import permutations

# Create a dictionary to convert each cow to a number.
tonum = dict()
tonum["Beatrice"] = 0
tonum["Belinda"] = 1
tonum["Bella"] = 2
tonum["Bessie"] = 3
tonum["Betsy"] = 4
tonum["Blue"] = 5
tonum["Buttercup"] = 6
tonum["Sue"] = 7

# Create a list to do the opposite
toname = ["Beatrice", "Belinda", "Bella", "Bessie", 
          "Betsy", "Blue", "Buttercup", "Sue"]

infile = open("lineup.in", "r")
outfile = open("lineup.out", "w")

n = int(infile.readline().strip())

checks = []

for i in range(n):
    line = infile.readline().strip().split()
    checks.append((tonum[line[0]],tonum[line[-1]])) # First and last cow - note that
                                                    # order doesn't matter.

perms = permutations([0,1,2,3,4,5,6,7])
for x in perms:
    # Small optimization: map each cow to it's position in the array
    pos = [0 for _ in range(8)]
    for y in range(8):
        pos[x[y]] = y

    good = True
    for c in checks:
        # Check if the two cows are adjacent.
        if (abs(pos[c[0]] - pos[c[1]]) != 1):
            good = False
            break
    
    if (good):
        for y in x:
            print(toname[y])
        break




