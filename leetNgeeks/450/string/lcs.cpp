

#include<bits/stdc++.h>
using namespace std;



namespace my {
	string ans;
}



// top down soln
int lcs(string a,string b,
	int i,int j) {
	
	
	int n1 = a.length();
	int n2 = b.length();

	if( i >= n1 or j >= n2) {
		return 0;
	}
	if(a[i] == b[j]) {
		my::ans += a[i];
		return lcs(a,b,i+1,j+1) + 1;
	}

	else if(a[i] != b[j] ) {

		return max(lcs(a,b,i+1,j),lcs(a,b,i,j+1));
	}


	
}



// bottom up soln
void lcs_efficient(string a,string b) {

	int m = a.length();
	int n = b.length();

	int dp[m+1][n+1];


	for(int i = 0; i < m; i++) {

		for(int j = 0;  j < n; j++) {

			if(i == 0 or  j == 0) {
				dp[i][j] = 0;
			}
			else if(a[i-1] == b[j-1]) {
				dp[i][j] = i + dp[i-1][j-1];
			}
			else if(a[i-1] != b[j-1]) {
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}

		}
	}

	cout<<dp[m][n];

}

int main() {
	string a;
	string b;

	cin>>a;
	cin>>b;


	cout<<lcs(a, b,0,0) <<endl;

	cout<<my::ans;

}