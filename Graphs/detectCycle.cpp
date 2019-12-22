

// detect cycle in graph using DFS
#include<bits/stdc++.h>
using namespace std;


bool isCycleUtil(vector<vector<int>> graph, int u,vector<bool> &visited,vector<bool> &Stack){


	if(visited[u] == false){
		visited[u] = true;
		Stack[u] = true;

		for(int i = 1; i < graph[u].size(); i++){
			if(!visited[graph[u][i]]  and isCycleUtil(graph,graph[u][i],visited,Stack)){
				return true;
			}
			else if(Stack[graph[u][i]]){
				return true;
			}
		}
	}
	Stack[u] = false;
	return false;

}

bool isCycle(vector<vector<int>> graph, int E,int V){
	vector<bool> visited(V);
	vector<bool> Stack(V);
	for(int i = 0; i < V; i++){
		visited[i] = false;
		Stack[i]   = false;
	}

	for(int i = 0; i < V; i++){
		if(isCycleUtil(graph,i,visited,Stack) == true){
			return true;
		}
	}
	return false;

}

int main(){
	int V; cin>>V;
	int E; cin>>E;
	vector<vector<int> > graph(V);

	for(int i = 0; i < E; i++){
		int u; cin>>u;
		int v; cin>>v;
		graph[u].push_back(v);
	}
	
	if(isCycle(graph,E,V)){
		cout<<"cycle is detected"<<endl;
	}
	else{
		cout<<"there is no cycle in Graph"<<endl;
	}
}