

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

void motherUtil(vector<vector<int>> &graph,vector<bool> &visited,int v){
	cout<<v<<" ";
	visited[v] = true;
	for(int i = 0; i< graph[v].size(); i++){
		motherUtil(graph,visited,graph[v][i]);
	}

}

void motherVertex(vector<vector<int>> graph, int V,int E){


	for(int i = 0; i < V; i++){

		vector<bool> visited(V);
		for(int i =0; i < V; i++){ visited[i] = false;}
		cout<<"expanding "<<i<<endl;
		motherUtil(graph,visited,i);

		if(check(visited)){
			cout<<"mother vertex "<<i<<endl;
			return;
		}
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

	cout<<"graph is\n";
	for(int i = 0; i <V; i++){
		for(int j = 0; j < graph[i].size(); j++){
			cout<<i<<"->"<<graph[i][j]<<endl;
		}
		
	}

	motherVertex(graph,V,E);
}