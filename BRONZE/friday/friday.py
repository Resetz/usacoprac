"""
ID: vincent97
LANG: PYTHON3
TASK: friday
"""
fin = open ('friday.in', 'r')
fout = open ('friday.out', 'w')


def is_leap(i):

    if i % 400 == 0:
        return True
    elif i % 100 == 0:
        return False
    elif i % 4 == 0:
        return True
    return False

def days_in_year(i):
    days = 365
    if is_leap(i):
        days -= 1
    return days

def days_in_month(mon, year):
    if mon==2:
        return 28 + int(is_leap(year))
    mons = [1,3,5,7,8,10,12]
    if mon in mons:
        return 31
    return 30


# input.
N = int(fin.readline().strip())

day_frequencies = [0 for _ in range(7) ]# days in weeks
# 0 is sunday, 6 is saturday
day = 0

days_gone_by = 0
for i in range(N):
    for mon in range(1,13):
        days_gone_by += 13
        day = (days_gone_by + 1) % 7
        day_frequencies[day] += 1
        days_gone_by += days_in_month(mon, i+1900) - 13

# output
for i in range(len(day_frequencies)):
    fout.write(str(day_frequencies[i]))
    if i != 6:
        fout.write(" ")
fout.write("\n")
    

