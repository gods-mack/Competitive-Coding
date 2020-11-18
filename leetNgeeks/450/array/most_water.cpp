
// 11. Container With Most Water

// https://leetcode.com/problems/container-with-most-water/

#include<bits/stdc++.h>
using namespace std;


void sol(vector<int> &a) {

	int n = a.size();
	int l = 0;
	int r = n-1;

	int res = INT_MIN;

	while( r > l) {

		int curr = min(a[l],a[r]) * (r-l);

		res = max(res,curr);

		if(a[l] > a[r]) {
			r--;
		}
		else{
			l++;
		}

	}

	cout<<"ans "<<res<<endl;
}

int main() {
	int n; cin>>n;
	vector<int> a(n);
	for(auto &x:a) cin>>x;

	sol(a);	
}