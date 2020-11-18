

#include<bits/stdc++.h>
using namespace std;


int all_palindrom(string s,int i,int j) {


	if( i > j) return 0;

 	if(i == j) {
		return 1;
	}

	if(s[i] == s[j]) {
		return all_palindrom(s,i+1,j) + all_palindrom(s,i,j-1)+1;
	}

	else{
		return all_palindrom(s,i+1,j) + all_palindrom(s,i,j-1) - all_palindrom(s,i+1,j-1);	
	}
}

int main() {
	string s;
	cin>>s;


	int n = s.length();
	cout<<all_palindrom(s,0,n-1);


}