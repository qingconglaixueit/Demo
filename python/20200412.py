#/usr/bin/python
#num%10 == 7 or num%7 == 0


def SkipSeven(num):
	if num%10 == 7 or num%7 == 0:
		return 1
	return 0

i = 1
while(i<101):
	if(SkipSeven(i)):
		print("{XX}\t",end='')
	else:
		print("{}\t".format(i),end='')
	if i%6 == 0:
		print("\n")
	i+=1
print("\n")
		

