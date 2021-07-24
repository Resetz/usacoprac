# The following code implement a stack using a Python List
stack = []

def isEmpty():
  # return true if stack is empty 
    if len(stack) <= 0:
        return True
    return False


def top():
    # return the top element of the stack 
    return stack[-1]

def push(item):
    # add the item to the top of stack
    # return the number of elements in the stack 
    stack.append(item)
    return len(stack) + 1 

def pop():
    # return the item on the top of the stack
    ret = stack[-1]
    stack.pop(-1)
    return ret

# code to read push and pop instruction
n = int(input("").strip())
for _ in range(n):
    instruction = input("").strip().split("")
    if instruction[0] == "PUSH":
        push(instruction[1])
    elif instruction[1] == "POP":
        pop()

print(len(stack))
for x in range(len(stack)):
    print(stack.pop())

