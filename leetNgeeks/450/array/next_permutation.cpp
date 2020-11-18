
// 31. Next Permutation
// https://leetcode.com/problems/next-permutation/

#include<bits/stdc++.h>
using namespace std;

void next_permut(vector<int> &a ) {


	int n = a.size();
	int f = 0; // flag

	for(int i = n-1; i>=1; i--) {

		if(a[i] > a[i-1]){
			f = 1;

			for(int j = n-1; j >= i; j--) {
				if(a[j] > a[i-1]){
					swap(a[j],a[i-1]);
					sort(a.begin()+(i),a.end());
					break;	
				}
			}
			break;
		
		}
	}

	

	if(!f){
		reverse(a.begin(),a.end());
	}
}


int main() {
	int n; cin>>n;
	vector<int>a(n);
	for(auto &x:a){
		cin>>x;
	}

	next_permut(a);

}