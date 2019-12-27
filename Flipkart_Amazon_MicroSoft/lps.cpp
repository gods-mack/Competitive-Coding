
// longest palindrom substring

// input: aaaabbaa
// output: aabbaa


#include<bits/stdc++.h>
using namespace std;

bool isPalindrom(string s){

	int l = 0;
	int r = (int)s.length() -1;

	while(l<=r){
		if(s[l] == s[r]){
			l++;
			r--;
		}
		else if(l==r){
			return true;
		}
		else{
			return false;
		}
	}
}

string longest_palindrom(string s){
	int n = (int)s.length();

    string final = "";
	string ans = "";
	int count = 0;

	for(int  i = 0; i < n; i++){
		ans = "";
		for(int j = i; j < n; j++){
			ans += s[j];
			if(count < (int)ans.length() and isPalindrom(ans)){
			//	cout<<"palindrom : "<<ans<<endl;
				count = (int)ans.length();
				final = ans;
			}
		}
	}
	return final;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		cout<<longest_palindrom( s)<<endl;
		//cout<<isPalindrom(s);
	}
}