"""
ID: your_id_here
LANG: PYTHON2
TASK: berries
"""
#Written by: Vincent Tran
#Dedicated to: Michael Tran
fin = open ('berries.in', 'r')
fout = open ('berries.out', 'w')
n, k = [int(x) for x in fin.readline().split()]
data = [int(x) for x in fin.readline().split()]



"""
File Out Methods
"""
fout.write (str(sum) + '\n')
fout.close()