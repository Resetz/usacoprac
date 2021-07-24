import random
fout = open ('cereal.in', 'w')

fout.write("10 5\n")
for x in range(10):
    num1 = random.randint(1, 5)
    num2 = random.randint(1, 5)
    while num1 == num2:
        num2 = random.randint(1, 5)

    fout.write(str(num1) + " " + str(num2) + "\n")
fout.close()