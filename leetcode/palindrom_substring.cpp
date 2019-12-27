
// longest palindrom substring using Dynamic programming O(n^2)


#include<bits/stdc++.h>
using namespace std;

string longest_palindrom(string s){

	int l;int r;
	int n = (int)s.length();
	string ans = "";

	int dp[n][n] = {0}; 
	memset(dp, 0, sizeof(dp[0][0]) * n * n);
	
	for(int i = 0; i < n; i++){  // fill cross part
		dp[i][i] = 1;
	}


	for(int i = 0; i< n-1; i++ ){
		if(s[i] == s[i+1]){
			l = i;
			r =  i+1;
			dp[i][i+1] = 1;
		}
	}

	for(int k = 3; k <= n; k++){

		for(int i = 0; i < (n-k+1); i++){

			int j = i+(k-1);
			if(dp[i+1][j-1] and s[i]==s[j]){
				l = i;
				r = j;
				dp[i][j] = 1;
			}
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}

	for(int i = l; i <=r; i++){
		ans += s[i];
	}

	return ans;


}

int main(){
	int t; // testcase
	cin>>t;
	while(t--){
		string s;
		cin>>s;

		cout<<longest_palindrom(s)<<endl;
	}
}