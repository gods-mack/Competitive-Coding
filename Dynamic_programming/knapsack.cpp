

#include<bits/stdc++.h>
using namespace std;





void knapsack(vector<int> val,vector<int> wt,int W){

	int n = val.size();
	int dp[n+1][W+1] ;


	for(int i = 0; i <= n; i++){

		for(int j = 0; j <= W; j++){
			if(i == 0 || j==0){
				dp[i][j] = 0;
			}
			else if(wt[i-1] > j){
				dp[i][j] = dp[i-1][j];
			}else{
				dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]],
							    dp[i-1][j]	);
			}
		}

	}

	for(int i = 1; i <=n; i++){
		for(int j = 1; j <= W; j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}

	cout<<"TOTAL: "<<dp[n][W]<<endl;

	// PRINTING ELEMENT
	int j = W;
	for(int i = n; i >= 1; i--){

		if(dp[i][j] == dp[i-1][j]){
			continue;
		}
		else{
			cout<<val[i-1]<<" ";
			j = j - wt[i-1];
		}
	}

}

int main(){
	int n; cin>>n;
	vector<int> value(n);
	vector<int> weight(n);
	for(int i = 0; i < n; i++){
		cin>>value[i];
	}
	for(int i = 0; i < n; i++){
		cin>>weight[i];
	}
	int W; cin>>W;

	knapsack(value,weight,W);

}