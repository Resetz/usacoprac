import beads
import random
def generate_necklace(length):
    necklace = []
    for x in range(length):
        letter = random.randint(1,3)
        if letter == 1:
            necklace.append("w")
        if letter == 2:
            necklace.append("r")
        if letter == 3:
            necklace.append("b")
    return ''.join(necklace)



print("-------------------------------------")
for x in range(10):
    fin = open("beads.in", "w")
    length = random.randint(3,50)
    necklace = generate_necklace(length)
    fin.write(str(length) + "\n")
    fin.write(necklace)
    fin.close()

    beads.main()

    fout = open("beads.out", "r")
    print("Necklace: " + necklace)
    print("Result:   " + fout.readline().strip())
    print("-------------------------------------")
    fout.close()