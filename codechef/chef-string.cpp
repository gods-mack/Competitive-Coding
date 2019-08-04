// uRL : https://www.codechef.com/LTIME25/problems/CHEFSTLT
/*
Example

Input:
3
a?c
??b
???a
???a
?abac
aba?w

Output:
1 3
0 3
3 5

*/



#include<bits/stdc++.h>

using namespace std;

int minV(string s1,string s2){
	int count = s1.length();

	for(int i = 0; i<s1.length(); i++){
		if(s1[i] == '?' ||  s2[i] == '?') {
			count--;
		}
		else{
			if(s1[i] == s2[i]){
				count--;
			}
		}
	}
	return count;
}

int maxV(string s1,string s2){
	int count  = s1.length();

	for(int i = 0; i<s1.length(); i++){
		if( (s1[i] == s2[i] ) and (s1[i]!='?' and s2[i]!='?' ) ){
			count--;
		}
	}
	return count;
}

int main(){
	int T; cin>>T;
	while(T--){
			string s1;
			string s2;
			cin>>s1>>s2;
			cout<<minV(s1,s2)<<" "<<maxV(s1,s2)<<endl;

	}
}
