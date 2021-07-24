
n = int(input(""))

data = []

for _ in range(n):
    data.append(0)

for _ in range(n-1):
    parse = [int(x)-1 for x in input("").strip().split(" ")]
    data[parse[0]] += 1
    data[parse[1]] += 1

print(max(data)+1)