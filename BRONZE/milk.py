import math
n, k = [int(n) for n in input("").strip().split()]
data = []

for _ in range(k):
    data.append([int(n) for n in input("").split().strip()])

def get_price(a):
    return a[0]

sorted(data, key=get_price)

index = 0
money = 0
while n - data[index][1] >= 0:
    n -= data[index][1] 
    money += data[index][0] * data[index][1] 
    index+=1

if (n == 0):
    print(money)
else:
    print(money + ceil(data[index][0] / n))
