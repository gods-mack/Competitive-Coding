/*
Triple Step: A child is running up a staircase with n steps
 and can hop either 1 step, 2 steps, or 3
steps at a time. Implement a method to count how many 
possible ways the child can run up the stairs.
*/

#include<bits/stdc++.h>
using namespace std;


int triple_step(int n) {
	if(n == 0) {
		return 1;
	}
	else if( n < 0) {
		return 0;
	}
	return triple_step(n-1)+triple_step(n-2)+triple_step(n-3);

}

void dp_sol(int n) {

	int dp[n+1];

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for(int i = 4; i <= n; i++) {

		dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
	} 

	cout<<"dp sol "<<dp[n]<<endl;
}

int main() {
	int n; cin>>n;

	cout<<triple_step(n)<<endl;
	dp_sol(n);

}