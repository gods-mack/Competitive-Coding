/*
You are given a number N. You have to find the number of operations required to reach N from 0. You have 2 operations available:

    Double the number
    Add one to the number


Explanation:
Testcase1:
Input  : N = 8
Output : 4
0 + 1 = 1, 1 + 1 = 2, 2 * 2 = 4, 4 * 2 = 8

*/

#include<bits/stdc++.h>
using namespace std;


// bottoom up
int minOper(int n){

	int memo[n+1]  = {0};
	memset(memo,0,n+1);
	for(int i = 1; i<=n; i++){
		if(i % 2 == 1){
			memo[i] = 1 + memo[i-1];
		}
		else{
			memo[i]  = min(1 + memo[i-1] , 1 + memo[i/2]);
		}
	}



	return memo[n];

}

int topdown(int n, int sum){

	if(sum == 0){
		return 0;
	}
	else if(sum % 2 == 1){
		return 1 + topdown(n, sum -1 );
	}
	else{
		return min ( 1 + topdown( n , sum -1 ), 1 + topdown(n, sum /2) );
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int* count = 0;
		cout<<minOper(n); // bottom up
		//cout<<topdown(n,n);  // top down
	}
}