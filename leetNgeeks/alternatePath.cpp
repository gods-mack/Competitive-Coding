

// https://leetcode.com/problems/find-eventual-safe-states/


#include<bits/stdc++.h>
using namespace std;



void dfs(int u,char clr, vector<vector<pair<int,char>>>& g,vector<int> &dis,vector<int> &vis){

	cout<<"dfs on "<<u<<" "<<clr<<" "<<g[u].size()<<endl;
	vis[u] = 1;
	if(g[u].size() == 0){
		cout<<"got here\n";
		return ;
	}
	for(int i = 0; i < g[u].size(); i++) {
		auto p = g[u][i]; // pair
		int v = p.first;
		char c = p.second; // color
		cout<<"v "<<v<<" "<<c<<endl;
		if(vis[v] == 2) {
			cout<<"clyle. "<<u<<" "<<v<<endl;
			continue;
		}
		if(clr != c && dis[u]+1 < dis[v]) {
			dis[v] = dis[u] + 1;
			dfs(v,c,g,dis,vis);
		}
		

	}
	vis[u] = 2;

}

void shortestAlternatingPaths(int V, vector<vector<int>>& red, vector<vector<int>>& blue) {

	vector<vector<pair<int,char>> > g(V);
	cout<<"r_Size "<<red.size()<<endl;

	for(int i = 0; i < red.size(); i++) {
		int x,y;
		x = red[i][0];
		y = red[i][1];
		cout<<x<<" "<<y<<" r \n";
		g[x].push_back({y,'r'});
	}
	for(int i = 0; i < blue.size(); i++) {
		int x,y;
		x = blue[i][0];
		y = blue[i][1];
		cout<<x<<" "<<y<<" b \n";
		g[x].push_back({y,'b'});
	}

	vector<int> vis(V,0);
	vector<int> dis(V);
	for(int i = 0; i < V; i++) {
		dis[i]  = INT_MAX;
	}
	dis[0] = 0;
//	auto p = g[0][0];

	cout<<"called\n"; 
	dfs(0,'s',g,dis,vis);

	cout<<"weight\n";

	for(auto x:dis) {
		if(x == INT_MAX){
			cout<<-1<<" ";
		}
		else{
			cout<<x<<" ";
		}
	}

}

int main() {

	int V; cin>>V;

	

	int re; // red edge
	int be; // blue edge
	cin>>re;
		vector<vector<int>> red;
	for(int i = 0; i < re; i++) {
		int x; cin>>x;
		int y; cin>>y;
		vector<int> tmp(2);
		tmp[0] = (x);
		tmp[1] = (y);
		red.push_back(tmp);
	}
	cin>>be;
	vector<vector<int>> blue;
	for(int i = 0; i < be; i++) {
		int x; cin>>x;
		int y; cin>>y;
		vector<int> tmp(2);
		tmp[0] = x;
		tmp[1] = y;
		blue.push_back(tmp);
	}
	
	cout<<"....\n";
	shortestAlternatingPaths(V,red,blue);



}





		