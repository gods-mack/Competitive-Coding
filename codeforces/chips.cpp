


#include<bits/stdc++.h>
using namespace std;

string solution(string s, int n, int k){
	string ans = "";
	ans = s;

	for(int i = 0; i < k; i++){

		for(int j = 0; j<n; j++){
			if(j == n-1){
				if(s[0] == s[j-1]){
					ans[j] = s[j-1];
				}
				else{
					ans[j] = s[j];
				}
			}
			else if(j == 0){
				if(s[j+1] == s[n-1]){
					ans[j] = s[j+1];
				}
				else{
					ans[j] = s[j];
				}

			}
			else{
				if(s[j-1] == s[j+1]){
					ans[j] = s[j-1];
				}
				else{
					ans[j] = s[j];
				}
			}
		}
		s = ans;
	
	}

	return ans;
}

int main(){
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;

	cout<<solution(s,n,k);
}