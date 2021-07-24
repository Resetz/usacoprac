"""
ID: vincent97
LANG: PYTHON3
TASK: moop
"""
fin = open ('moop.in', 'r')
fout = open ('moop.out', 'w')

def cmp(a):
    return a[1]

def can_kill(a,b):
    #print(a,"and",b,"can kill eachother?", a[0] >= b[0] and a[1] >= b[1])
    if a[0] >= b[0] and a[1] >= b[1]:
        #print(a, "can kill", b)

        return True
    ##print(a, "cannot kill", b)
# a[0] = x
# a[1] = y
# input.
N = int(fin.readline().strip())
##print(num_of_names)
particles = []
for i in range(N):
    particles.append(fin.readline().split(" "))
    particles[i][1] = int(particles[i][1].strip())
    particles[i][0] = int(particles[i][0])

particles.sort(key=cmp, reverse=True)

##print(particles)

previous_particles = []
squares = []
num_of_squares = 0
for i in particles:
    could_find_suitable_square = []
    for square in squares:
        found_valid = False
        for j in square:
            if can_kill(i,j) or can_kill(j,i):
                found_valid = True
                ##print(i, "can kill", j)
                break
        if found_valid:
            #square.append(i)
            could_find_suitable_square.append(squares.index(square))

    if len(could_find_suitable_square) > 1:
        for j in range(len(could_find_suitable_square)):
            if j == 0:
                continue
            for k in squares[could_find_suitable_square[j]]:
                squares[could_find_suitable_square[0]].append(k)
        #print(could_find_suitable_square, len(squares))
        first = True
        for j in sorted(could_find_suitable_square,  reverse=True):
            if first:
                first = not first
                continue
            squares.pop(j)
        squares[could_find_suitable_square[0]].append(i)
    elif len(could_find_suitable_square) == 1:
        squares[could_find_suitable_square[0]].append(i) 
    else:
        squares.append([i])

            
#print("squares = [")
#for square in squares:
    #print("    ",square)
#print("]")
##print(squares)
#print("squares = [")
#for i in squares:
    #print("[length is " + str(len(i)) + "]")
#print("]")
fout.write(str(len(squares)))
fout.close()
    
        

        
        
        
        





#fout.write(str(names[i]) + " " + str(int(total_money[i])) + "\n")
#fout.close()
        
    

