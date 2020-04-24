

#include<bits/stdc++.h>
using namespace std;



// TOP DOWN

int topDown(vector<int> a,int l,int r,int day ){

	if(l == r){
		return a[l]*day;
	}
	else {
		return max(a[l]*day+topDown(a,l+1,r,day+1),
					a[r]*day+topDown(a,l,r-1,day+1));
	}
}


// BOTTOM Up SOL.
int bottomUp(vector<int> a,int l,int r,int day,vector<vector<int> >dp){

	if(l == r){
		return a[l]*day;
	}
	else if(dp[l][r]==0){ //if not calculated already
		dp[l][r] = max(a[l]*day+bottomUp(a,l+1,r,day+1,dp),
			           a[r]*day+bottomUp(a,l,r-1,day+1,dp));
	}

	return dp[l][r];

}



int main(){
	int n; cin>>n;
	vector<int> wines(n);
	for(int i =0 ; i < n; i++){
		cin>>wines[i];
	}

	vector<vector<int>> dp(n + 1, vector<int>(n + 1)); 
	//cout<<topDown(wines,0,n-1,1);

	cout<<bottomUp(wines,0,n-1,1,dp);

}