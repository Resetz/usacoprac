milk = [0, 0, 0]
size = [0, 0, 0]

for x in range(3):
    size[x], milk[x] = (int(x) for x in input().strip().split(" "))

#simulate 99 pours
for x in range(33):
    #pouring from bucket 1 -> 2
    topour = min(size[1]-milk[1], milk[0])
    milk[0] -= topour
    milk[1] += topour

    #pouring from bucket 2 -> 3
    topour = min(size[2]-milk[2], milk[1])
    milk[1] -= topour
    milk[2] += topour

    #pouring from bucket 3 -> 1
    topour = min(size[0]-milk[0], milk[2])
    milk[2] -= topour
    milk[0] += topour

#finish last pour
topour = min(size[1]-milk[1], milk[0])
milk[0] -= topour
milk[1] += topour

print(milk[0])
print(milk[1])
print(milk[2])
