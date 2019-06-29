
/*
Write a function to check whether two given strings are anagram of each other or not.
An anagram of a string is another string that contains same characters, only the order of characters can be different. 
For example, “abcd” and “dabc” are anagram of each other.

Solution : . If we start at a value of 0 and XOR all the characters of both strings, 
we should return an end value of 0 if they are anagrams because 
there would be an even occurrence of all characters in the anagram. 

time : O(n)
space: O(1)

*/

#include <bits/stdc++.h> 
using namespace std; 

// Function to check whether two strings are anagram of 
bool areAnagram(string str1, string str2) 
{ 
	// If two strings have different size 
	if (str1.size() != str2.size()) { 
		return false; 
	} 

	int value = 0; 

	for (int i = 0; i < str1.size(); i++) { 
		value = value ^ (int) str1[i];     // XOR 
		value = value ^ (int) str2[i]; 
	} 

	return value == 0; 

} 

// Driver code 
int main() 
{ 
	string str1 = "geeksforgeeks"; 
	string str2 = "forgeeksgeeks"; 
	if (areAnagram(str1, str2)) 
		cout << "strings are anagram of each other"; 
	else
		cout << "strings are not angram to each other"; 

	 
} 
