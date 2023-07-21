fin = open("word.in", "r")
fout = open("word.out", "w")
n, m = [int(x) for x in fin.readline().strip().split(" ")]
words = fin.readline().strip().split(" ")
curLen = 0
s = ""
for x in words:
    if (curLen + len(x) > m):
        s = s[:len(s)-1] + "\n"
        s += x + " "
        curLen = len(x)
    else:
        s += x + " "
        curLen += len(x)
fout.write(s[:len(s)-1])
