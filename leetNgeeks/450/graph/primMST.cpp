

#include<bits/stdc++.h>
using namespace std;



void primMST() {


	vector<int> parent(V,-1);
	vector<int> dis(V,INT_MAX);
	vector<int> vis(V,false);


	dis[0] = 0;


	while(1) { // V-1 times

		int u = minKey(dis,vis,g);
		if(u == -1) {
			return;
		}

		vis[u] = true;
		for(int i =0; i < g[u].size(); i++) {

			int v = g[u][i].first;
			int w = g[u][i].second;

		//	int total = dis[u]+w;
			if(!vis[v] and w < dis[v])  {
				dis[v] = w;
				parent[v] = u;
			}
		}
	}
}

int main() {
	int V; cin>>V;
	vector<vector<pair<int,int> > > g(V);
	int E; cin>>E;

	for(int i = 0; i < E; i++) {
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}


}