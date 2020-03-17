#import numpy as np
import array as ar

t = (input())


def count_set_bits(n):
    count = 0
    while n:
        n &= n - 1
        count += 1
    return count

while(t):
	tmp = []
	for i in range(2):
		tmp.append(input())
	n = int(tmp[0])
	q = int(tmp[1])
	#a = ar.array('i',[])
	print(n,q)
	a = []
	for i in n:
		print("helo")
		#x1 = int(input())
		x = input().split(" ")
		a.append(x)
	while(q):
		p = (input())
		even = 0
		odd = 0
		for i in n:
			x  = (int(p) ^ int(a[i]) )
			res = count_set_bits(x)
			if(res%2 == 0):
				even = even + 1
			else:
				odd = odd + 1
		print(even,odd)			 
		q = q - 1	
	t = t - 1