

/*
 You are given a sorted array containing both 
 negative and positive values. Resort the array 
 taking absolute value of negative numbers.
  Your complexity should be O(n)


  Ex. A = {-8,-5,-3,-1,3,6,9}
Output: {-1,-3,3,-5,6,-8,9} 

*/

#include<bits/stdc++.h>
using namespace std;


void resort(vector<int> &a){


	int par ;
	for(int i = 0; i < a.size(); i++){
		if(a[i] >= 0) {
			par = i;
			break;
		}
	}

	int l = par-1;
	int r = par;
	vector<int> b;

	int ind = 0;

	while(l >= 0 and r < a.size()) {

		if(abs(a[l]) > a[r]) {
			b.push_back(a[r]);
			r++;
		}
		else if(abs(a[l]) < a[r]){
			b.push_back(a[l]);
			l--;
		}
		else{
			b.push_back(a[l]);
			l--;
		}
	}

	while(l >= 0) {
		b.push_back(a[l]);
		l--;
	}
	while(r < a.size()) {
		b.push_back(a[r]);
		r++;
	}

	for(auto x:b) {
		cout<<x<<" ";
	}
}

int main() {
	int n; cin>>n;
	vector<int>a(n);
	for(auto &x:a){
		cin>>x;
	}

	resort(a);
}