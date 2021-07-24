"""
ID: vincent97
LANG: PYTHON3
TASK: milk2
"""
fin = open ('milk2.in', 'r')
fout = open ('milk2.out', 'w')

times = []
for _ in range(int(fin.readline().strip())):
  times.append(fin.readline().split())

for x in times:
    x[0] = int(x[0])
    x[1] = int(x[1])
start = times[0][0] -1
end = times[0][0] -1


def first_elem(a):
  return a[0]
times = sorted(times, key = first_elem)

first = True

longest_milk = 0
longest_break = 0

print(times)
for x in times:
  if first:
      start = x[0]
      end = x[1]
      first = False
      print("skip")
      print(start, end, x)
      continue
  if x[0] >= end:
    print("got here", x[0] - end > longest_break, longest_milk < end - start)
    if longest_break < x[0] - end:
      longest_break = x[0] - end
    if longest_milk < end - start:
      longest_milk = end - start
    if x[0] > end:
      start = x[0]
    end = x[1]
    
  elif x[0] < end:
    if x[1] > end:
      print(start, end, x)
      end = x[1]

  print(start, end, x)
if longest_break < x[0] - end:
  longest_break = x[0] - end
if longest_milk < end - start:
  longest_milk = end - start

fout.write(str(longest_milk) + " " + str(longest_break) + "\n")