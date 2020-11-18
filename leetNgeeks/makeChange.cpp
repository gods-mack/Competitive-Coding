

#include<bits/stdc++.h>
using namespace std;



//int ans = 0;


int changeTopDown(vector<int> a, int total,int i){
	if(total == 0){
		return 1;
	}
	if(total < 0){
		return 0;
	}
	if(total >= 1 and i<=0){
		return 0;
	}

	return changeTopDown(a,total-a[i-1],i) + changeTopDown(a,total,i-1);

}

void bottom_up(vector<int> coins,int W) {

	int n = coins.size();


	int dp[W+1][n];

	for(int i = 0; i < n; i++) {
		dp[0][i] = 1;
	}


	for(int i = 1; i <= W; i++) {

		for(int j = 0; j < n; j++) {

			int x,y;
			if(i-coins[j] >=0 ){
				x = dp[i-coins[j]][j];
			}
			else{
				x = 0;
			}
			if(j >= 1) 
				y = dp[i][j-1];
			else
				y = 0;

			dp[i][j] = x+y;
		}
	}


	for(int i = 0; i <= W; i++) {
		for(int j = 0; j < n; j++) {
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main() {
	int n; cin>>n;
	vector<int> coins(n);
	for(int i = 0; i < n; i++) {
		cin>>coins[i];
	}

	int W; cin>>W;

	int ans = 0;
	//cout<<makeChange(coins,W,ans);
	cout<<changeTopDown(coins,W,n)<<endl;

	bottom_up(coins,W);

	//cout<<"ans "<<ans<<endl;

}