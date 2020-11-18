
#include<bits/stdc++.h>
using namespace std;

void wordBreak(string s,vector<string> dict) {
	unordered_set<string> st;

	for(auto x:dict){
		st.insert(x);
	}

	int n = s.length();
   
    bool dp[n+1] = {false};	
    dp[0] = true;

	for(int i = 1; i < n+1; i++) {


		for(int j = i-1; j > -1; j--) {

			//string tmp = s.substr(j,i-j);
			if(dp[j] && st.find(s.substr(j,i-j)) != st.end()) {
				dp[i] = true;
				break;
			}
		}
	}


	for(auto x:dp) {
		cout<<x<<" ";
	}



}

int main() {
	string s;
	cin>>s;

	int n; cin>>n; // dict size

	vector<string> dict(n);
	for(auto &x:dict) cin>>x;


	wordBreak(s,dict);	
}