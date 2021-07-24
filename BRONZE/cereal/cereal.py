"""
ID: vincent97
LANG: PYTHON3
TASK: cereal
"""
fin = open ('cereal.in', 'r')
fout = open ('cereal.out', 'w')

N, boxes = fin.readline().strip().split(" ")
N = int(N)
boxes = int(boxes)

print(N, "cows,", boxes, "boxes")

cows = []
for _ in range(N):
    cows.append(fin.readline().strip().split(" "))
#print(cows)
food_already_eaten = []
cows_eating_food = []
ans = []
#print(list(range(N-1,0, -1)))

all_food_eaten = 0
for x in range(N):
    print(x)
    

    counter = all_food_eaten
    #print(all_food_eaten)
    if x == 0:
        pass
    elif x in cows_eating_food:
        food_already_eaten = []
        cows_eating_food = []
    else:
        ans.append(food_already_eaten)
        continue


    if (len(food_already_eaten) > N-x):
        #print("err, food_already_eaten's length is greater than the amount of cows being checked")
        pass

    if all_food_eaten == 0:
        counter = x
    while counter < N:
        if len(food_already_eaten) == boxes:
            #all_food_eaten = counter
            break
    
        if counter in cows_eating_food:
            counter += 1
            continue
        if cows[counter][0] in food_already_eaten:
            if cows[counter][1] in food_already_eaten:
                counter += 1
                continue
            
            else:
                cows_eating_food.append(counter)
                food_already_eaten.append(cows[counter][1])
        else:
            cows_eating_food.append(counter)
            food_already_eaten.append(cows[counter][0])
        counter += 1
    print(food_already_eaten[:5])
    #print(cows_eating_food)
    
    ans.append(len(food_already_eaten))
    
for x in ans:
    fout.write(str(x) + "\n")

fout.close()

        

                