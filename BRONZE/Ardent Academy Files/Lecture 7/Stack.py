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


def pop(stack):
    # return the item on the top of the stack
    return stack.pop()


# code to read push and pop instruction
equation = list(input("").strip())


opening_symbols = ["{", "[", "("]
ending_symbols = ["}", "]", ")"]
ending_symbols_in_queue = []
opening_symbols_in_queue = []

for x in range(len(equation)):
    symbol = pop(equation)
    if symbol in ending_symbols:
        push(ending_symbols_in_queue, symbol)
    if symbol in opening_symbols:
        push(opening_symbols_in_queue, symbol)

complete = True
while not isEmpty(ending_symbols_in_queue) and not isEmpty(opening_symbols_in_queue):
   if not pop(opening_symbols_in_queue) == pop(ending_symbols_in_queue):
       complete = False
       break
if complete:
    print("VALID")
else:
    print("NOT VALID")    





