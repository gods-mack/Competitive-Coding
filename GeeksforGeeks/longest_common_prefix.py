# Given a array of N strings, find the longest common prefix among all strings present in the array.
"""
Example
Example:
Input:
2
4
geeksforgeeks geeks geek geezer
3
apple ape april

Output:
gee
ap
"""



def common_prefix(vector):

	print(vector)	
	min_string = min(vector,key=len)
	print("minimum string ",min_string," ",len(min_string))
	vector.remove(min_string)
	print("after removing min_string ",vector)
	T = len(vector)
	print("T ",T)
	#print(len(vector))
	flag =  0
	flag_str = "" 


	for t in range(len(min_string),0,-1):
		count = 0
		curr  = ""
		forv in vector:
			if(v.startswith(min_string[0:t])):
				count = count + 1
				curr = min_string[0:t]
			else:
				break		
		if(count==T):
			#print("curr ",curr)
			flag = 1;
			flagstr = curr
			break
	if(flag):
		print(flagstr)
	else:
		print("-1")					
		


T = int(input())
while(T>0):

	vector = []
	N = int(input())
	nn = N
	x = input()
	vector = x.split(" ")
	if(N==1):  ## if we have only single string 
		print(x)
	else:		
		common_prefix(vector)	
	T = T-1	




	


