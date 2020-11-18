
// https://leetcode.com/problems/keys-and-rooms/



#include<bits/stdc++.h>
using namespace std;

set<int> s;


void allpath(vector<vector<int>>&g,int u,vector<int> &vis) {

//	tmp.push_back(u);

	vis[u] = 1;



	for(int i = 0; i < g[u].size(); i++) {
		if(vis[g[u][i]]) {
			continue;
		}
		s.insert(g[u][i]);
		allpath(g,g[u][i],vis);
	}

}


int main() {

	int V; cin>>V;
	int E; cin>>E;
	vector<vector<int>> graph(V);
	for(int i = 0; i < E; i++) {
		int x,y;
		cin>>x>>y;
		graph[x].push_back(y);
	}



	vector<int> visited(V,0);
	

	s.insert(0);
	allpath(graph,0,visited);
	
	if(s.size() == V) {
		cout<<"connecd\n";
	}
	else{
		cout<<"NOt conn\n";
	}

	
	
}



