
// leetcode zigZag conversion

#include<bits/stdc++.h>
using namespace std;


string zigZag(string s, int n){

	if(n == 1){
		return s;
	}

	int j  = 0;
	int slen = s.length();
	string tmp[slen];


	//printStack(stak);	

	int flag0 = 0; // to go downside
	int flagn = 0; // to go upside

	for(int i = 0; i < slen; i++){

		tmp[j].push_back(s[i]);

		if(j==0){
			flag0=1;
			flagn = 0;
		}
		if(j == n-1){
			flagn = 1;
			flag0 = 0;
		}
		if(flag0){
			j++;
		}
		else{
			j--;
		}
		
	}

	string ans = "";
	for(int i = 0; i < n; i++){

		for(int j = 0; j < tmp[i].length(); j++){
			ans += tmp[i][j];
		}
	}

	return ans;
}

int main(){
	string s;
	cin>>s;
	int n;
	cin>>n;

	cout<<zigZag(s,n)<<endl;
}