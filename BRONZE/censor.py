infile = open("censor.in","r")
outfile = open("censor.out","w")

string = infile.readline().strip()
censor = infile.readline().strip()

while censor in string:
    string = string.replace(censor, '', 1)
    
outfile.write(string)

infile.close()
outfile.close()