// mother vertex
/*

A mother vertex in a graph is a vertex from which 
we can reach all the nodes in the graph through directed path. 
n other words, A mother vertex in a graph G = (V,E) 
is a vertex v such that all other vertices in G can be 
reached by a path from v.

*/

// find mother vertex of a graph(V,E)

#include<bits/stdc++.h>
using namespace std;

bool check(vector<bool> visited){

	for(auto x: visited){
		if(!x){
			return false;
		}
	}
	return true;
}

void motherUtil(vector<vector<int>> &graph,vector<bool> &visited,int &visitCount,int v){
	//cout<<v<<" ";	
	visited[v] = true;
	visitCount++;
	for(int i = 0; i< graph[v].size(); i++){
		if(visited[graph[v][i]]==false){
			motherUtil(graph,visited,visitCount,graph[v][i]);
		}
	}

}

int motherVertex(vector<vector<int>> graph, int V,int E){

	int i = 0;
	for(i = 0; i < V; i++){

		vector<bool> visited(V,false);
		int visitCount = 0;
		motherUtil(graph,visited,visitCount,i);
		if(visitCount == V){
			break;
		}

		
	}
	if(i==V){
		return -1;
	}
	else{
		return  i;
	}
	 
}

int main(){
	int V; cin>>V;
	int E; cin>>E;
	vector<vector<int>> graph(V);

	for(int i = 0; i < E; i++){
		int u; cin>>u;
		int v; cin>>v;
		graph[u].push_back(v);
	}

	

	cout<<"mother "<<motherVertex(graph,V,E)<<endl;
}