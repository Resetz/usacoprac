def isEmpty(stack):
    # return true if stack is empty
    return len(stack) <= 0


def top(stack):
    # return the top element of the stack
    return stack[-1]


def push(stack, item):
    # add the item to the top of stack
    # return the number of elements in the stack
    stack.append(item)
    return len(stack) + 1

def move(stack1, stack2):
    element = pop(stack1)
    if element == None:
        return False
    stack2.push(stack2, element)
    return True

def pop(stack):
    # return the item on the top of the stack
    return stack.pop()


n = input("")
towers = [[x for x in range(n)],[],[]]


def printstack(stack):
    builder = ""
    for x in stack:
        if len(x) == 0:
            builder = builder + "_"
        else:
            for y in x:
                builder = builder + str(y)


def hanoi(fromstack,tostack,extrastack):
    #where fromstack is the stack we want to move
    #tostack is the ending stack
    #extrastack is the stack that where the remainders should be stored
    if len(towers[fromstack]) == 0:
        return

    for _ in range(len(towers[fromstack])-1):
        move(towers[fromstack],towers[extrastack])
    
    move(towers[fromstack], towers[tostack])





