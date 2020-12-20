
#include<bits/stdc++.h>
using namespace std;




int main() {

	int V; cin>>V;

	vector<vector<int> > g(V);
	int E; cin>>E;

	set<pair<int,int>> st;
	for(int i = 0; i < E; i++) {
		int u,v;
		cin>>u>>v;

		st.push_back({u,v});

		g[u].push_back(v);
		g[v].push_back(u);
	} 

	




}