// Longest common subsequence using Bottom Up approach

#include<bits/stdc++.h>
using namespace std;



int lcs(string s1, string s2, int m, int n){

	int memo[m+1][n+1];



	for(int i = 0; i <= m; i++){
		for(int j = 0;  j <= n; j++){

			if(i==0 or j==0){
				memo[i][j] = 0;
			}

			else if(s1[i-1] == s2[j-1]){
				memo[i][j] = memo[i-1][j-1] + 1;
			}
			else{
				memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
			}
		}
	}

	cout<<"answer "<<memo[m][n];
	return memo[m][n];

}

int main(){
	string s1;
	string s2;
	cin>>s1>>s2;

	cout<<lcs(s1,s2,(int)s1.length(), (int)s2.length())<<endl;
}