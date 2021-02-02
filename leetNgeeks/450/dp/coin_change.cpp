


#include<bits/stdc++.h>
using namespace std;

namespace my {
	int count = 0;
}

int demo(vector<int> &a,int ind,int sum) {

	if(sum < 0) {
		return 0;
	}
	if(sum == 0) {
		return 1;
	}
	if(ind < 0 and sum > 0) {
		return 0;
	}

	return demo(a,ind-1,sum) + demo(a,ind,sum-a[ind]);
}

int botttomUP(vector<int> a, int sum) {

	int N = a.size();
	int dp[N+1][sum+1] ;

	for(int i  = 0; i < N+1; i++) {
		for(int j = 0; j < sum+1; j++) {
			dp[i][j] = 0;
		}
		
	}

	// Initializing first column of array to 1
    // because a sum of 0 can be made
    // in one possible way: {0}
    for(int i = 0; i < N + 1; i++){
        dp[i][0] = 1;
    }
    

	for(int ind = 1; ind < N+1; ind++) {

		for(int j = 1; j < sum+1; j++) {

			if(a[ind-1] > j) { // sum > 0
				dp[ind][j] = dp[ind-1][j];
			}
			else{
				dp[ind][j] = dp[ind-1][j]+dp[ind][j-a[ind-1]];
			}
		}
	}

	for(int i  = 0; i < N+1; i++) {
		for(int j = 0; j < sum+1; j++) {
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}




}

int main() {

	int n; cin>>n;
	vector<int> a(n);
	for(auto &x:a){
		cin>>x;
	}


	int sum; cin>>sum;
	botttomUP(a,sum);
	cout<<"\nans "<<demo(a,n-1,sum);

}
	