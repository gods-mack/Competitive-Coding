

#include<bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	while(t--) {
		int m,n; cin>>m>>n;
		vector<vector<int> > a(m);

		for(int i = 0; i < m; i++){
			a[i].resize(n);
			for(int j = 0; j < n; j++) {
				cin>>a[i][j];
			}
		}


	}
}