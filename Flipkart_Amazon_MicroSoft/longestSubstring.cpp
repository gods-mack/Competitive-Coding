

#include<bits/stdc++.h>
using namespace std;

int longestSubstring(string s){
	int n  = s.length();

	map<char,int> mpp;
	int p = 0; // tracing pointer
	int count = 0;
	int i = 0;

	int flag = 1;
	while(i < n){

		if(mpp[s[i]] == 0){
			mpp[s[i]]++;
		}
		else{
			flag = 0;
			if(count < (abs(i-p)) ){
				count = abs(i-p);

			}
			    p += 1;
				i = p;
				mpp.clear();
				mpp[s[p]]++;

		}

		i++;
	}

	if(flag == 1){
		return n;
	}
	else if(abs(i-p) > count){ // last portion of string is answer "dhadabcde" >> "abcde"
		count = abs(i-p);
		return count;
	}
	else{
		return count;
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		cout<<longestSubstring(s)<<endl;
	}
}