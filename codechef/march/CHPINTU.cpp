

#include<bits/stdc++.h>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		int m; cin>>m;

		vector<int> f(n);
		vector<int> p(n);
		for(int i=0;i<n;i++){ cin>>f[i];}
		for(int i=0;i<n;i++){ cin>>p[i];}

		map<int,int> hs;
		int ans = INT_MAX;
		for(int i = 0; i < n; i++){
			hs[f[i]] += p[i];
		}	
		for(auto it=hs.begin();it!=hs.end();++it){
			ans = min(ans,it->second);
		}
		cout<<ans<<endl;
	}
}