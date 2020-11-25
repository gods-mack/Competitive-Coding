

#include<bits/stdc++.h>

using namespace std;



int min_key(vector<int>&dis,vector<int> &vis, vector<vector<pair<int,int>>> &g)	 {


	int min_index = -1;
	int min_value = INT_MAX;


	for(int i = 0; i < dis.size(); i++) {

		if(dis[i] < min_value && !vis[i]) {

			min_value = dis[i] ;
			min_index =  i;
		}
	}

	return min_index;
}

void dijkstra_path(vector<vector<pair<int,int>>>g, int src) {

	int V = g.size();
	vector<int> vis(V,false);
	vector<int> dis(V,INT_MAX);

	dis[src] = 0;



	for(int count = 0; count < V-1; count++) {

		int u = min_key(dis,vis,g);
		cout<<"u "<<u<<endl;
		if(u == -1) break;


		for(int i = 0; i < g[u].size(); i++) {
			
			int v = g[u][i].first;
			int total = dis[u]+g[u][i].second;

			if(!vis[v] && total < dis[v]) {
				dis[v] = total;
			}
		}
		vis[u] = true;
	}


	cout<<"dis array\n";
	for(auto x:dis) {
		cout<<x<<" ";
	}
}


int main() {
	int V; cin>>V;
	int E; cin>>E;
	vector<vector<pair<int,int>>> g(V);
	for(int i = 0; i < E; i++) {
		int x,y,w;
		cin>>x>>y>>w;
		g[x].push_back({y,w});
	}

	dijkstra_path(g,0);


}