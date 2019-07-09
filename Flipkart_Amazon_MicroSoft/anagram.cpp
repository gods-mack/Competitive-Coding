/*
Given two strings a and b consisting of lowercase characters. 
The task is to check whether two given strings are anagram of each other or not.
An anagram of a string is another string that contains same characters, only the order of
characters can be different. For example, “act” and “tac” are anagram of each other.

*/

#include<bits/stdc++.h>
using namespace std;

void anagram(string a, string b){
	
	if(a.length() == b.length()){
		int val = 0;
		for(int i=0; i<a.length(); i++){
			val = val^a[i];
			val = val^b[i];
		}
		if(val==0){
			cout<<"YES";
		}
		else{
			cout<<"NO";
		}
	}
	else{
		cout<<"NO";
	}


} // end of anagram func

int main(){
	
	int T; cin>>T;
	while(T--){
		string a;
		cin>>a;
		string b;
		cin>>b;
		anagram(a,b);
		cout<<endl;
	}
}
	
