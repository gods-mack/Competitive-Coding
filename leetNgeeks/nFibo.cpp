
#include<bits/stdc++.h>
using namespace std;



void fib(int n){

	int dp[n+1];

	dp[0] = 0;
	dp[1] = 1;

	for(int i = 2; i<=n; i++) {
		dp[i] = dp[i-2] + dp[i-1]; // fib(n-2)+fib(n-1)
	}

	if(n%2==0){
		for(int i=1; i <= n; i++) {
			cout<<dp[i]<<" ";
		}
	}
	else{
		for(int i = n; i>=1; i--) {
			cout<<dp[i]<<" ";
		}
	}
}

int main() {
	int n; cin>>n;
	//cout<<fib(n)<<endl;
	fib(n);

}