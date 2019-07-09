/*
Given a string, the task is to remove duplicates from it. 
Expected time complexity O(n) where n is length of input string and extra space O(1) under
the assumption that there are total 256 possible characters in a string.

Note: that original order of characters must be kept same. 

*/



#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
using namespace std;

void removeDuplicate(string s){
	int freq[256] = {0};   // it is constant space because its size does not depend on string size
	
	int size = s.length();
	for(int i = 0;i<size; i++){
		if(freq[(int)s[i]] ==0){
			cout<<s[i];
			freq[(int)s[i]]++;
		}
		
	}
}
	

int main(){
	int T; cin>>T; // testCase
	cin.ignore();
	while(T--){
		string s;
		//cin.ignore();
		//cin>>s;
		getline(cin,s);
		//scanf (”%[^]%*c", s);
		removeDuplicate(s);
		cout<<endl;
	}
}
