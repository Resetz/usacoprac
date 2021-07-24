n, q = [int(x) for x in input("").strip().split(" ")]
string = input("").strip()

def min_strokes(string):
    highest_order = 0
    highest_orders = []

    strokes = 0

    for x in range(len(string)):
        if ord(string[x]) > highest_order:
            highest_order = ord(string[x])
            highest_orders = []
            highest_orders.append([x])
        if ord(string[x]) == highest_order:
            if highest_orders[-1][-1] - x == 1:
                highest_orders[-1].append(x)
            else:
                highest_orders[-1].append(x)
    
    print(highest_orders)
    strokes += len(highest_orders)
    while True:
        index = 0
        if highest_orders[0][0] -1 <= 0 and highest_orders[0][1] >= len(string):
            strokes += 1
            break
        for x in highest_orders:
            left, right = 0, 0
            if not x[-1]+1 >= len(string):
                if ord(string[x[0]-1]) > ord(string[x[-1]+1]):
                    x.insert(0, ord(string[x[0]-1]))
                    left = 2
                    right = -1

                    for y in range(x[1], x[-1]):
                        x[y] = ord(string[x[0]-1])
            if not x[0]-1 <= 0:
                if ord(string[x[0]-1]) < ord(string[x[-1]+1]):
                    x.append(ord(string[x[0]-1]))
                    left = -1
                    right = 2

                    for y in range(x[0], x[-2]):
                        x[y] = ord(string[x[0]-1])
            if not x[0]-1 <= 0 and not x[-1]+1 >= len(string):
                if string[x[0]-1] == string[x[-1]+1]:
                    x.insert(0, ord(string[x[0]-1]))
                    x.append(ord(string[x[0]-1]))
                    left = 2
                    right = 2

                    for y in range(x[1], x[-2]):
                        x[y] = ord(string[x[0]-1])


            while True:
                if left == -1 and right == -1:
                    break
                print("left", left, "right", right)
                if x[0] - left <= 0:
                    left = -1
                if x[1] + right >= len(string):
                    right = -1
                if left != -1:
                    if string[x[0]-left] == string[x[0]-1]:
                        x.insert(0, string[x[0]-1])
                        right += 1
                    else:
                        left = -1
                if right != -1:
                    if string[x[-1]+right] == string[x[-1]+1]:
                        x.insert(0, string[x[0]-1])
                        right += 1
                    else:
                        right = -1
            
            if index+1 >= len(highest_orders):
                break
            if x[-1] in highest_orders[index+1]:
                for y in x:
                    highest_orders[index+1].append(x[-1])
                highest_orders.pop(index)

            index += 1
            print(highest_orders)
        strokes += len(highest_orders)

ranges = []
for _ in range(q):
    ranges.append([int(x)-1 for x in input("").strip().split(" ")])

print(ranges)
for x in range(q):
    check_string = string

    print(ranges[x][0], ranges[x][1]+1)
    for y in range(ranges[x][0], ranges[x][1]+1):
        print(y, list(check_string))
        temp = list(check_string)
        temp[y] = "."
        check_string = "".join(temp)

    print(check_string)
    split_string = check_string.split(".")
    print(split_string)
    print(min_strokes(split_string[-1]))
        
    

