// Given is an integer N. Find the number of digits that N has in base K.

#include<bits/stdc++.h>

using namespace std;

int main(){
	long long int n; cin>>n;
	int k; cin>>k;

	int count= 0;
	while(n!=0){	
		n = n/k;
		count++;
	}
	cout<<count;


}