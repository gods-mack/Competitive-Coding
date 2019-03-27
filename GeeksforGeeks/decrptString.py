# Given a string str consisting of characters and numbers and an integer k, 
# the task is to decrypt the string and the return the kth 
# character in the decrypted string.
# For example, str = “ab2c3” will be decrypted as “ababcababcababc”.

# input: str = “ab2c3”, k = 5
# Output: c
# Decrypted string will be “ababcababcababc” and ‘c’ is the fifth character.
# Input: str = “x2y3”, k = 3
# Output: y 


s = input()
k = int(input())

n = str()  # new String

for  i in range(0,len(s)):
  if(ord(s[i])>=97 and ord(s[i])<=122 ):
	      n = n + s[i];
  else:
         num   = int(s[i])	
         #print(num)
         n = n*(num)

print(n[k-1])	
print(n)

del(n) # delete temp string
