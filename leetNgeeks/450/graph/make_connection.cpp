
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

int count_component(vector<vector<int>> g,int n) {

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
//	cout<<"count "<<count<<endl;

	return count;
}

int makeConnected(int n, vector<vector<int>>& connections) {
        
        
        int edge_count = connections.size();
        if(edge_count < n-1) {
            return -1;
        }
        
        vector<vector<int>> g(n);
        for(int i = 0; i < edge_count; i++) {
            g[connections[i][0]].push_back(connections[i][1]);
            g[connections[i][1]].push_back(connections[i][0]);
        }
        
        int total_compo = count_component(g,n);
        
        return total_compo - 1;
        
        
    }

int main() {
	
	
}