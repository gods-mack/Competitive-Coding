

// https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string/0


/*

NOTE: there is difference between longest palin substring
and subsequence 

*/

#include<bits/stdc++.h>
using namespace std;


bool isPalin(string s) {
	int l = 0;
	int r = s.length()-1;

	while(r >= l) {
		if(s[l] == s[r]){
			l++;
			r--;
		}
		else{
			return false;
		}
	}

	return true;
}

// brute force O(N^3)
void long_palin_subtring__(string s) {


	int count = 0;

	string ans = "";
	int n = s.length();
	for(int i = 0; i < n; i++) {

		string tmp = "";
		for(int j = i; j < n; j++) {
			tmp += s[j];
			if(isPalin(tmp)) {
				if(count < j-i+1){
					ans = tmp;
					count = j-i+1;
				}
			}
		}
	}


	cout<<"ans "<<ans<<endl;
}



// dp approch O(N^2)
void longest_palin_substring(string s) {

	int n = s.length();
	bool dp[n][n];
	int start = 0;
	int max_length = INT_MIN;

	// fill cross
	// for one char string
	for(int i = 0; i < n; i++) {
		dp[i][i] = true;
	}

	// for two char string
	for(int i = 0; i < n-1; i++) {

		if(s[i] == s[i+1]) {
			dp[i][i+1] = true;
		}
	}

	for(int k = 3; k < n; k++) {

		for(int i = 0; i < n-k+1; i++) {
			int j = i+k - 1;
			if(s[i] == s[j] && dp[i+1][j-1]==true){
				
				if(max_length < k) {
					max_length = k;
					start = i;
				}
				dp[i][j] = true;
			}
		}
	}
}



// longest palindrom subsequence

// top down O( 2^N )
int longest_palin_subsequence__(string s, int i, int j) {

	if(i > j ) {
		return 0;
	}
	if(i == j) {
		return 1;
	}

	if(s[i] == s[j] and i+1==j) {
		return 2;
	}


	if(s[i] == s[j]) {
		return longest_palin_subsequence__(s,i+1,j-1)+2;
	}
	return max(longest_palin_subsequence__(s,i+1,j),
			longest_palin_subsequence__(s,i,j-1));
}



// bottom up approach O(n^2_)
void longest_palin_subsequence(string s) {

	int n = s.length();
	int dp[n][n];


	// i char subseq
	for(int i = 0; i < n; i++) {
		dp[i][i] = 1;
	}

	int max_length = 1;

	for(int k = 2; k <= n; k++) {

		for(int i = 0; i < n-k+1; i++) {
			int j = i + k - 1 ;

			if(s[i] == s[j] and k == 2) {
				max_length = max(max_length,2);
				dp[i][j] = 2;
			}
			else if(s[i] == s[j]) {
				dp[i][j] = dp[i+1][j-1] + 2;
				max_length = max(max_length,dp[i][j]);
			}
			else{
				dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
				max_length = max(max_length,dp[i][j]);
			}
		}
	}


	cout<<"lcs "<<max_length<<endl;


}

int main() {
	string s;
	cin>>s;

	//longest_palin_substring(s);



	longest_palin_subsequence(s);
	//cout<<longest_palin_subsequence(s,0,s.length()-1);


}