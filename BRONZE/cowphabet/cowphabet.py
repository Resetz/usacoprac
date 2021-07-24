
alpha = input("")
hummed = input("")

minimum = 1

index = 0
prev_index = 0
for x in hummed:
    cur_index = alpha.index(x)
    if prev_index > cur_index:
        minimum += 1
    prev_index = cur_index + 1
print(minimum)