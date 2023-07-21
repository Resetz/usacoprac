infile = open("convention.in", "r")
outfile = open("convention.out", "w")

n,m,c = [int(x) for x in infile.readline().strip().split(" ")]
cows = [int(x) for x in infile.readline().strip().split(" ")]

cows = sorted(cows)

# YOUR CODE GOES HERE
# Determine whether or not a value of k will have all cows depart.
# Return True/False.

def go(k):
    allCowsDepart = True

    busesLeft = m-1
    waitingCow = 0 # assume the first cow is "waiting"
    for x in range(1, n):
        if (cows[x] - cows[waitingCow] > k or x - waitingCow + 1 > c):
            busesLeft -= 1
            waitingCow = x
        
        if (busesLeft < 0):
            # Used up all buses
            allCowsDepart = False
            break
    
    return allCowsDepart

# If you would like to look at a "solution":
# The pos(int wait) function of this solution performs the same thing:
# http://www.usaco.org/current/data/sol_convention_silver_dec18.html

# Alternatively, you can look at mine on the slides.


# Binary Search
low = 0
high = 1000000000
ans = 0
while (high >= low):
    mid = low + (high - low) // 2
    if (go(mid)):
        high = mid-1
        ans = mid
    else:
        low = mid+1

outfile.write(str(ans))

infile.close()
outfile.close()