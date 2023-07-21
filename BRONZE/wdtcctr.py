infile = open("cowqueue.in", "r")
outfile = open("cowqueue.out","w")

n = int(infile.readline().strip())

cows = []
for i in range(n):
    a, b = [int(x) for x in infile.readline().strip().split(" ")]
    cows.append([a,b])

# * Sorting * #
# Depending on your language, this line may be different
cows = sorted(cows)
# * Sorting * #

lastCowFinished = 0
for cow in cows:
    
    # The current cow doesn't need to wait. Starts right as it arrives
    if (lastCowFinished <= cow[0]):
        lastCowFinished = cow[0] + cow[1]
    
    # The current cow needs to wait until the previous one is finished.
    # The cow will start when the last cow finishes.
    else:
        lastCowFinished = lastCowFinished + cow[1]

outfile.write(str(lastCowFinished))

infile.close()
outfile.close()
