

// 33. Search in Rotated Sorted Array

	#include<bits/stdc++.h>
using namespace std;

int find_pivot(vector<int> a,int l,int r) {

	if(r < l) {
		return -1;
	}
	if(r == l) {
		return l;
	}

	int m =(l+r)/2;
	cout<<"now mid "<<m<<endl; 

	if(a[m] > a[m+1]) {
		return m;
	}
	if(a[m] < a[m-1]) {
		return m-1;
	}

	if(a[l] >= a[m])
		return find_pivot(a,l,m-1);
	return find_pivot(a,m+1,r);
	

}



int binary_search(vector<int> &a,int l,int r,int tar) {


	if(l <= r) {
		int m = (l+r)/2;

		if(a[m] == tar) {
			return m;
		}

		if(a[m] > tar) {
			return binary_search(a,l,m-1,tar);
		}
		else{
			return binary_search(a,m+1,r,tar);
		}

	}
	return -1;
}


void search_(vector<int> &a,int tar) {

	int n = a.size();
	
	int pivot = find_pivot(a,0,n-1);

	cout<<"pivot "<<pivot<<endl;

	if(if)a[0] <= tar and tar < a[pivot]) {
		cout<<binary_search(a,0,pivot,tar);
	}
	else{
		cout<<binary_search(a,pivot+1,n-1,tar);
	}



}

int main() {
	int n; cin>>n;
	vector<int> a(n);
	for(auto &x:a){
		cin>>x;
	}

	int target; cin>>target;


	search_(a,target);
}