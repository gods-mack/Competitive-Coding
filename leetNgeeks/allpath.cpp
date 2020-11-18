

// https://leetcode.com/problems/all-paths-from-source-to-target/






#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;


void allpath(vector<vector<int>>&g,int u,int x,vector<int> &tmp) {

	tmp.push_back(u);

	if(u == x ){
		ans.push_back(tmp);
	}

	for(int i = 0; i < g[u].size(); i++) {
		allpath(g,g[u][i],x,tmp);
	}

	tmp.pop_back();
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
	
	vector<int>tmp;

	allpath(graph,0,V-1,tmp);
	

	for(auto x:ans) {
		for(auto y:x){
			cout<<y<<" ";
		}
		cout<<endl;
	}
	
}



