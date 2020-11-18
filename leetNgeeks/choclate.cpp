

#include<bits/stdc++.h>
using namespace std;


void sol(vector<int> &a,int n,int m) {

	sort(a.begin(),a.end());

	int ans = INT_MAX;
	for(int i = 0; i < n; i++) {

		if(i+m <= n){
			ans = min(ans,a[i+m - 1]-a[i]);
		}

	}

	cout<<ans<<endl;
}


int main() {
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vector<int> a(n);

		for(int i = 0;i<n;i++){
			cin>>a[i];
		}
		int m; cin>>m;

		sol(a,n,m);
	}
}