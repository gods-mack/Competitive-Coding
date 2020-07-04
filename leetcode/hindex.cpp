

// H-INDEX

/*
Given an array of citations (each citation is
 a non-negative integer) of a researcher, 
 write a function to compute the researcher's h-index.

*/


#include<bits/stdc++.h>
using namespace std;

int hindex(vector<int> a,int l,int r,int &res) {
	if(a.size() == 0) {
	return 0;
	}



	if(l <= r) {
		int mid = (l+r)/2;
		int n = a.size();
		if(res < (n-mid) && a[mid]>=(n-mid)) {
			res = (n-mid);
			hindex(a,l,mid-1,res);

		}
		else{
			//hindex(a,l,mid-1,res);
			hindex(a,mid+1,r,res);
		}

	}
	return res;
}


int main() {
	int n; cin>>n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	int res = 0;
	cout<<hindex(a,0,n-1,res);


}