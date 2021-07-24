"""
ID: vincent97
LANG: PYTHON3
TASK: beads
"""

fin = open ('beads.in', 'r')
fout = open ('beads.out', 'w')


length = int(fin.readline().strip())
beads = fin.readline().strip()
print(beads)
max_counted = 0
for i in range(length):
    #print(i)
    color = beads[i]
    counted = 1 #count the first one.
    #scan to the right
    continue_to_wrap = True
    for j in range(i+1, length):
        if (color == 'w'):
            if (beads[j] != 'w'):
                color = beads[j]
                counted += 1
                print(beads[j], end="")
                continue
            else:
                print(beads[j], end="")
                counted += 1
        elif (color != beads[j]):
            if (beads[j] == 'w'):
                print(beads[j], end="")
                counted += 1
                continue
            else:
                continue_to_wrap = False
                break
        else:
            print(beads[j], end="")
            counted += 1
    if continue_to_wrap:
        for j in range(i):
            if (color != beads[j]):
                if (beads[j] == 'w'):
                    print(beads[j], end="")
                    counted += 1
                    continue
                else:
                    continue_to_wrap = False
                    break
            else:
                print(beads[j], end="")
                counted += 1
    #scan to the left
    print("")
    color = beads[i-1]
    for j in range(i-1, -length, -1):
        if (color == 'w'):
            if (beads[j] != 'w'):
                color = beads[j]
                print(beads[j], end="")
                counted += 1
                continue
            else:
                print(beads[j], end="")
                counted += 1
        elif (color != beads[j]):
            if (beads[j] == 'w'):
                print(beads[j], end="")
                counted += 1
                continue
            else:
                break
        else:
            print(beads[j], end="")
            counted += 1
    
    if (counted >= length):
        max_counted = length
        break
    if (counted > max_counted):
        max_counted = counted
    print("\n----------------------------")

fout.write(str(max_counted) + "\n")
fout.close()

