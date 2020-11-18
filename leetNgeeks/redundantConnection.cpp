
// UNidirected graph
// https://leetcode.com/problems/redundant-connection/

#include<bits/stdc++.h>
using namespace std;


int find_set(int u, vector<int> &parent) {

	if(u==parent[u]){
		return u;
	}
	parent[u] = find_set(parent[u],parent);
	return parent[u];
}

void union_set(int x,int y, vector<int> &parent) {
	int a = find_set(x,parent);
	int b = find_set(y,parent);

	parent[b] = a;


}

 void findRedundantConnection(vector<vector<int>>& edges){
       
  	int V = edges.size();
  	if(V==0){
  		return;
  	}
 
	vector<int> parent;
	for(int i =0;i<=V;i++)
		parent.push_back(i);
	
	int x_ans,y_ans;
	for(int i = 0; i < edges.size(); i++) {

		int x = find_set(edges[i][0],parent);
		int y = find_set(edges[i][1],parent);

	
		if(x == y){
			x_ans = edges[i][0];
			y_ans = edges[i][1];
		}
		else{
			union_set(edges[i][0],edges[i][1],parent);
		}
	}

	
	cout<<"\nans "<<x_ans<<" "<<y_ans<<endl;


}

int main() {

	int V; cin>>V;
	int E;cin>>E;
	vector<vector<int>> graph(V);

	vector<int> degree(V);

	

	for(int i = 0; i < E; i++) {
		int x,y;
		cin>>x>>y;

		graph[i].push_back(x);
		graph[i].push_back(y);
		//graph[y].push_back(x);
		
	}

	findRedundantConnection(graph);

}