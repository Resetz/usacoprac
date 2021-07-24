import sys

print(sys.argv)

fin_1 = open(sys.argv[1], "r")
fin_2 = open(sys.argv[2], "r")

line1 = "a"
line2 = "a"
done = True
line = 0
while True:
    line1 = fin_1.readline()
    line2 = fin_2.readline()
    line += 1
    if (line1 == '' and line2 == ''):
        break
    if (line1 == '' or line2 == ''):
        done = False
        break
    if not (line1 == line2):
        done = False
        break
if done:
    print("Output matches.")
else:
    print("Error | Line =", line)
    print("\"" + line1.strip() + "\" doesn't match with " + "\"" + line2.strip() + "\"")
