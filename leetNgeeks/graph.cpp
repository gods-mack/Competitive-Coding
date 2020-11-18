
#include<bits/stdc++.h>
using namespace std;





void topo_sortUtil(vector<vector<int>> &graph,int u,vector<int> &visited,stack<int> &st){

	visited[u] = 0;
	for(int v = 0; v < graph[u].size(); v++){


		if(visited[graph[u][v]]==0){
			cout<<"cycle cant be a topo_sort\n";
			return;
		}
		else{
			if(visited[graph[u][v]] != 1){
				topo_sortUtil(graph,graph[u][v],visited,st);
			}
		}
	}

	visited[u] = 1;
	st.push(u);


}



void topo_sort(vector<vector<int> > graph,int V){


	vector<int> visited(V,-1);
	stack<int> st;

	for(int i = 0; i < V; i++) {
		if(visited[i]!=1){

			topo_sortUtil(graph,i,visited,st);
		}
	}

	while(!st.empty()) {
		cout<<st.top()<<" ";
		st.pop();
	}
}


bool isConnected(vector<vector<int>> graph,int V) {	

	queue<int> q;
	vector<bool> visited(V,false);

	q.push(0);

	set<int> st;
	st.insert(0);

	while(!q.empty()) {

		int u= q.front();
		q.pop();

		visited[u] = true;

		for(int i = 0; i < graph[u].size(); i++){
			if(!visited[graph[u][i]]){
				st.insert(graph[u][i]);
				q.push(graph[u][i]);
			}
		}
	}

	//cout<<"sixe "<<st.size();
	if(st.size() == V) {
		return true;
	}
	
	return false;



}


void bridge_in(vector<vector<int>> graph) {

	for(int i = 0; i < V; i++) {
		
	}
}

int minKey(vector<int>&dis,vector<bool>&vis) {
	int min_ind = -1;

	int min_val = INT_MAX;
	for(int i = 0; i < dis.size(); i++) {
		if(min_val > dis[i] && !vis[i]){
			min_val = dis[i];
			min_ind = i;
		}
	}
	return min_ind;
}

void MST_prim(vector<vector<pair<int,unsigned int>>> graph,int V){

	vector<int> dis(V,INT_MAX);
	vector<bool> vis(V,false);
	vector<int> parent(V);

	dis[0] = 0;
	parent[0] = -1;

	while(1) {
		int u = minKey(dis,vis);
		if(u == -1){
			break;
		}


		vis[u] = true;
		for(int i = 0; i < graph[u].size(); i++) {
			auto p = graph[u][i];
			int v = p.first;
			int w = p.second;

			if(!vis[v] and w < dis[v]) {
				parent[v] = u;
				dis[v] = w;
			}

		}
	}

	for(int i = 0; i <V; i++) {
		cout<<parent[i]<<" ";
	}
}





int main() {
	int V; cin>>V;
	int E; cin>>E;

	/*vector<vector<int> > graph(V);

	int u, v;
	for(int i = 0; i < E; i++){
		cin>>u>>v;
		graph[u].push_back(v); // directed

	}
	topo_sort(graph,V);

	isConnected(graph,V);
	*/


	/*** unidirected weighted graph input */
	vector<vector<pair<int,unsigned int>> > g;
	for(int i = 0; i <E; i++) {
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back(make_pair(v,w));
		g[v].push_back(make_pair(u,w));
	}

	MST_prim(g,V);






}