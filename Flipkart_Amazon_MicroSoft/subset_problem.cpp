
/*

// https://practice.geeksforgeeks.org/problems/subset-sum-problem/0

Given a set of numbers, check whether 
it can be partitioned into two subsets such that the sum of elements 
in both subsets is same or not.

*/



#include <bits/stdc++.h>
using namespace std;



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
    int t; cin>>t;
    while(t--){
	int n; cin>>n;
	vector<int> sbst(n);
	
	int sum = 0;
	for(int i = 0; i < n; i++){
		cin>>sbst[i];
		sum += sbst[i];
	}
	
//	int sum; cin>>sum;
	
	//int total = 0;
	if(sum % 2 == 1){
	    cout<<"NO"<<endl;
	    continue;
	}
	
	//cout<<setsum(sbst,total,sum,n-1);
    if(	bottom_up( sbst ,sum/2)){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
    }
	
}
