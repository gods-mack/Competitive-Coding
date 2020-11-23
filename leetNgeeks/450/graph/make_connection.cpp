
// 1319. Number of Operations to Make Network Connected
// https://leetcode.com/problems/number-of-operations-to-make-network-connected/

#include<bits/stdc++.h>
using namespace std;


void dfs(int u,vector<vector<int>> &g,vector<int> &vis) {

	//cout<<"now "<<u<<endl;
	vis[u] = true;

	for(int i = 0; i < g[u].size(); i++) {

		if(vis[g[u][i]] != true) {
			dfs(g[u][i],g,vis);
		}
	}
}

void count_component(vector<vector<int>> g,int n) {

	//cout<<"dd..\n";
	vector<int> vis(n,false);

	int count = 0;

	for(int i = 0; i < n; i++) {

		if(vis[i] == false) {
			//cout<<"time\n";
			dfs(i,g,vis);
			count++;
		}
	}
	cout<<"count "<<count<<endl;
}

int main() {
	int n; cin>>n;

	int e; cin>>e;
	vector<vector<int>> g(n);

	for(int i = 0; i < e; i++) {
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);

	}
	count_component(g,n);
}