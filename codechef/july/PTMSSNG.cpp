

#include<bits/stdc++.h>
using namespace std;

int main() {

ios_base::sync_with_stdio(false);
    cin.tie(NULL);


	int t; cin>>t;
	while(t--) {
		int n; cin>>n;
		map<long int,int> xx;
		map<long int,int> yy;
		for(int i = 0; i < 4*n - 1; i++) {
			long int xxx; cin>>xxx;
			long int yyy; cin>>yyy;
			xx[xxx]++;
			yy[yyy]++;
		}

		for(auto it=xx.begin(); it!=xx.end(); ++it) {
			if(it->second % 2 != 0) {
				cout<<it->first<<" ";
				break;
			}
		}
		for(auto it=yy.begin(); it!=yy.end(); ++it) {
			if(it->second % 2 != 0) {
				cout<<it->first<<endl;
				break;
			}
		}
	}
}