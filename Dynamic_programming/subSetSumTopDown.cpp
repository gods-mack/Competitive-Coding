
#include<bits/stdc++.h>
using namespace std;


// TOPDOWN
bool sumSetSum(vector<int> a , int sum, int index){

	if(sum == 0){
		return true;
	}
	if(index == 0 and sum != 0){
		return false;
	}
	if(sum < a[index-1]){ // if last element is grater than sum than igonre ot
		return sumSetSum(a,sum,index-1);
	}
	
	if(sum > 0){
		return sumSetSum(a, sum, index-1) ||  sumSetSum(a, sum-a[index-1],  index-1); 
	}
	
} 


// bOTTOM UP
bool bottom_up(vector<int> a, int sum){
	
	int n = a.size();
	bool dp[n+1][sum+1] ;
	
	
	
	for(int i = 0; i <= n; i++){
		dp[i][0] = true;
	}
	
	for(int i = 1; i <= sum; i++){
		dp[0][i] = false;
	}
	
	for(int i = 1; i <= n; i++){
		
		for(int j = 1; j <= sum; j++){
			
			if(j < a[i-1]){
				dp[i][j] = dp[i-1][j];
			}

			if(j >= a[i-1]){
				dp[i][j] = dp[i-1][j] or dp[i-1][j-a[i-1]] ;
			}
			
				
		}
	}
	
	
	
	return dp[n][sum];
	
}


int main(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	int sum; cin>>sum;

	if(sumSetSum(a,sum,n)){
		cout<<"yes\n";
	}else{
		cout<<"NO";
	}
}