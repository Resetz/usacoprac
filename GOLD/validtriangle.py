n = int(input())
for _ in range(n):
    a,b,c = [int(x) for x in input().strip().split(" ")]
    if (a+b > c and a+c > b and b+c > a):
        print("Yes")
    else:
        print("No")