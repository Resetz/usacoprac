# n - length of the fence
# k - amount of intervals
# string - string itself
# k intervals - intervals
#

def find_foward_strokes(s, forward = True):
    #print(s)
    if len(s) == 0:
        #print("returned", 0)
        return 0
    stack = []
    stack.append(s[0])
    strokes = 1
    
    been_past = []
    counter = 0
    solutions = {}
    solutions[0] = 0

    for x in s[0:]:
        been_past.append(x)
        #print(been_past)
        counter += 1
        if x == stack[-1]:
            solutions[counter] = strokes
            continue
        elif x > stack[-1]:
            strokes += 1
        else:
            ended = False
            while len(stack) != 0:
                if stack[-1] == x:
                    ended = True
                    break
                if stack[-1] < x:
                    strokes += 1
                    ended = True
                    break
                stack.pop(-1)
            if ended == False:
                if counter != 1:
                    strokes+=1
        if x not in stack:
            stack.append(x)
        solutions[counter] = strokes
    return solutions
    #print("returned", strokes)
    





n, k = [int(x) for x in input("").strip().split(" ")]
string = [x for x in input("").strip()]

intervals = []


for _ in range(k):
    intervals.append([int(x) - 1 for x in input("").strip().split(" ")])



strokes = 1


ret = []
memo_forward = find_foward_strokes(string)
memo_backward = find_foward_strokes(string[::-1])
start = 0
end = 0
cur_string = ""
total_value = 0

for x in intervals:
    #print(x[0], "|", n - x[1])
    ret.append(memo_forward[x[0]] + memo_backward[n - x[1] - 1])
for x in ret:
    print(x)
