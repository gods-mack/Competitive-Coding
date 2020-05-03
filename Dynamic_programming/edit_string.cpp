

// Edit Distance String problem

#include<bits/stdc++.h>
using namespace std;


// TOP DOWN APPRO..
int topDown(string a, string b, int m,int n) {

	if(m == 0){
		return n;
	}
	if(n == 0){
		return m;
	}
	if(a[m-1] == b[n-1]){
		return topDown(a,b,m-1,n-1);
	}
	else{
		return 1 + min(topDown(a,b,m-1,n), // remove
					   min(topDown(a,b,m-1,n-1),  // replace
					   topDown(a,b,m,n-1)));    // insert
	}
}

// BOTTOM UP APPRO..

void bottomUp(string a, string b,int m,int n) {

	int dp[m+1][n+1];


	for(int i = 0; i <= m; i++){

		for(int j = 0; j <= n; j++){

			if( i == 0 ){
				dp[i][j] = j;
			}
			else if(j == 0){
				dp[i][j] = i;
			}
			else if(a[i-1] == b[j-1]) {
				dp[i][j] = dp[i-1][j-1];
			}	
			else{
				dp[i][j] = 1 + 
							min(dp[i-1][j],
							min(dp[i-1][j-1],
								dp[i][j-1])
							);
			}
		}
	}

	cout<<"Table "<<endl;
	for(int i = 0; i <=m ;i++){
		for(int j = 0; j <=n; j++){
			cout<<dp[i][j] <<" ";
		}
		cout<<endl;
	}

	cout<<"Min Edit Dis: "<<dp[m][n];


}

int main(){

	string a,b;
	cin>>a>>b;

	int m  = a.length();
	int n = b.length();
	cout<<topDown(a,b,m,n)<<endl;
	bottomUp(a,b,m,n);
}