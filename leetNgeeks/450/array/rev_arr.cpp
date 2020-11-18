

#include<bits/stdc++.h>
using namespace std;


void rev(vector<int> &a ) {

	int l = 0;
	int r = a.size()-1;

	while(l <= r) {
		swap(a[l],a[r]);
		l++;
		r--;
	}
}

int main() {
	int n; cin>>n;
	vector<int> a(n);
	for(auto &x:a)cin>>x;

	rev(a);

	for(auto x:a){
		cout<<x<<" ";
	}
}