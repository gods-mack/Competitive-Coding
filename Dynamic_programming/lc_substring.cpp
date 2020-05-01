

// longest common substring

#include<bits/stdc++.h>
using namespace std;



//TOPDOWN
int check(string a, string b,int m,int n,int tmp) {

	if(m==0 or n==0){
		return tmp;
	}
	if(a[m-1] == b[n-1]){
		
		tmp = check(a,b,m-1,n-1,tmp+1);
	}
	else {
		
		tmp =  max(tmp,max(check(a,b,m-1,n,0),check(a,b,m,n-1,0)));
	}
	return tmp;
}


//BOTTOM-UP 

void lc_substring(string a,string n){

	int n = a.length();
	int m = b.length();

	int dp[n+1][m+1];


	int result = 0;
	for(int i = 0; i <= n; i++){

		for(int j = 0; j <=m; j++){
			if(i == 0 || j == 0){
				dp[i][j] = 0;
			}
			else if(a[i-1] == b[j-1]){
				dp[i][j]  = 1 + dp[i-1][j-1];
				result = max(result, dp[i][j]);
			}
			else{
				dp[i][j] = 0;
			}
		}
	}

	cout<<"longest common substring "<<result<<endl;
}


int main(){

	string a,b;
	cin>>a>>b;

	int tmp = 0;
	int ans = 0;
	cout<<check(a,b,a.length(),b.length(),tmp);
}