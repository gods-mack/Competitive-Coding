

//  Minimum number of jumps 

/*
https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps/0
*/

#include<bits/stdc++.h>
using namespace std;


void min_jump(vector<int> &a) {

	int n = a.size();
	int dp[n];
	for(auto &x:dp){
		x = INT_MAX;
	}


	if(a[0] > 0) {
		dp[0] = 0;
	}
	else{
	    cout<<-1<<endl;
	    return;
	}

	
    
    int maxx_jump = -999;

	for(int i = 0; i < n; i++) {
		int curr_jump = a[i];
		if(a[i] == 0 and i!=n-1) {
		    if(maxx_jump <= i) {
		        cout<<-1<<endl;
		        return;
		    }
		} 
		for(int j = i+1; j <= i+curr_jump and j<n; j++) {
			//cout<<"ins.."<<j<<" "<<i<<endl;
			int res = min(dp[j],dp[i]+1);
			maxx_jump = max(maxx_jump,j);
 			//cout<<"Res "<<res<<endl;
			dp[j] = res;
		}
	}

    cout<<dp[n-1]<<endl;
}

int main() {


int t; cin>>t;
while(t--) {
	int n; cin>>n;
	vector<int> a(n);
	for(auto &x:a) cin>>x;

	min_jump(a);
}

}