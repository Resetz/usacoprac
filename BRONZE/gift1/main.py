"""
ID: vincent97
LANG: PYTHON3
TASK: gift1
"""
fin = open ('gift1.in', 'r')
fout = open ('gift1.out', 'w')

# input.
num_of_names = int(fin.readline().strip())
#print(num_of_names)
names = []
for _ in range(num_of_names):
    names.append(fin.readline().strip())
print(names)
total_money = [0 for i in range(num_of_names)]
for i in range(num_of_names):
    name = fin.readline().strip()
    money, num = fin.readline().strip().split()
    num = int(num)
    if num == 0:
        continue
    money = int(money)
    money -= money % num
    total_money[names.index(name)] -= money
    money /= num

    for _ in range(num):
        total_money[names.index(fin.readline().strip())] += money
    print(name, "gave", money, "to", num, "people...")
    print(total_money)

for i in range(len(names)):
    fout.write(str(names[i]) + " " + str(int(total_money[i])) + "\n")
fout.close()
        
    

