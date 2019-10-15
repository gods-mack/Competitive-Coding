/*

Given a N X N  matrix Matrix[N][N] of positive integers.  There are only three possible moves from a cell Matrix[r][c].

1. Matrix[r+1][c]

2. Matrix[r+1][c-1]

3. Matrix[r+1][c+1]

Starting from any column in row 0, return the largest sum of any of the paths up to row N-1.

*/


#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n; int mat[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) cin>>mat[i][j];
        }
        int dp[n+1][n+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(i==0 or j==0){
                    dp[i][j]=0;
                }
                else dp[i][j]=max(dp[i-1][j],max(dp[i-1][j+1],dp[i-1][j-1]))+mat[i-1][j-1];
            }
        }
        int maxi=INT_MIN;
        for(int i=0;i<=n;i++) maxi=max(dp[n][i],maxi);
        cout<<maxi<<endl;
    }
	return 0;
}