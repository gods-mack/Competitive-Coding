

// First and last occurrences of X in sorted array

#include<bits/stdc++.h>
using namespace std;


int b_search(vector<int> &a,int l,int r,int x) {

	if(r < l) {
		return -1;
	}

	int mid = (l+r)/2;
	if(a[mid] == x) {
		return mid;
	}
	else if(a[mid] > x) {
		return b_search(a,l,mid-1,x);
	}
	else{
		return b_search(a,mid+1,r,x);
	}
}

void sol(vector<int> &a,int x) {


	int n  = a.size();
	cout<<"found at "<<b_search(a,0,n-1,x);
	int ind = b_search(a,0,n-1,x);

	int left = ind;
	int right = ind;
	while(a[left] == x && left > 0) {
		left--;
	}
	while(a[right] == x && right < n) {
		right++;
	}
}

int main(){

	int n; cin>>n;
	vector<int> a(n);
	for(auto &x:a) {
		cin>>x;
	}

	int x; cin>>x;
	sol(a,x);
    
}
