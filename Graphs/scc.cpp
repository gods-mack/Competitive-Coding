
// strong connect components (SCC) of graph

#include<bits/stdc++.h>
using namespace std;


void DFSutil(vector<vector<int>> GT, int u, vector<bool> &visited){
	cout<<u<<" ";
	visited[u] = true;

	for(int i = 0; i < GT[u].size(); i++){
		if(visited[GT[u][i]] == false){
			DFSutil(GT,GT[u][i],visited);
		}
	}
}

void DFS(vector<vector<int>> graph, int v,vector<bool> &visited,stack<int> &st){

	visited[v] = true;

	for(int i = 0; i < graph[v].size(); i++){
		if(visited[graph[v][i]] == false ){
			DFS(graph,graph[v][i],visited,st);
		}
	}
	st.push(v);
}


int SCC(vector<vector<int>> graph, int V, int E){
	vector<bool> visited(V);
	int count  = 0;
	for(int i  = 0; i < V; i++){
		visited[i] = false;
	}
	stack<int> st;
	//st.push(0);
	//visited[0]  = true;


	for(int i  = 0; i < V; i++){
		if(visited[i] == false){
			DFS(graph,i,visited,st);
		}
	}

	for(int i  = 0; i < V; i++){
		visited[i] = false;
	}

	vector<vector<int> > GT(V); // graph trnspose
	for(int i = 0; i < V; i++ ){
		for(int j = 0; j < graph[i].size(); j++){
			GT[graph[i][j]].push_back(i);
		}
	}
	 
	cout<<endl;
	 while(!st.empty()){
	 	int u = st.top();
	 	st.pop();
	 	if(visited[u] == false){
	 		DFSutil(GT,u,visited);
	 		cout<<endl;
	 		count++;
	 	}

	 }
	 cout<<"\n\n"<<count; .// number of connected graphs


}

int main(){
	int t; cin>>t;
	while(t--){ // testcase
		int V; cin>>V;
		int E; cin>>E;
		vector<vector<int>> graph(V);
		for(int i = 0; i < E; i++){
			int x; int y;
			cin>>x>>y;
			graph[x].push_back(y);
		}
		SCC(graph,V,E);
		cout<<endl;
	}
}