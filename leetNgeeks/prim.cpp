

#include<bits/stdc++.h>
using namespace std;



int minKey(vector<int> &key,vector<bool> &vis) {

	int ind;
	int val = 99999;

	for(int i =0 ; i < key.size(); i++) {
		if(vis[i] == false && val > key[i] ){
			val = key[i];
			ind = i;
		}
	}

	if(val == 99999) {
		return -1;
	}
	else{
		return ind;
	
	}
}




void prim(vector<vector<int>> &graph,int V) {

	cout<<"PRIM_ALGORITHm\n";
	vector<bool> vis(V,false);
	vector<int> key(V,INT_MAX);
	vector<int> parent(V);

	key[0] = 0;
	parent[0] = -1;

	for(int i = 0; i < V-1; i++){

		int u = minKey(key,vis);
	
		vis[u] = true;

		for(int j = 0; j < graph[u].size(); j++) {

			if(graph[u][j] && vis[j]==false && graph[u][j] < key[j]){

				parent[j] = u;
				key[j] = graph[u][j];
			}
		}
	}

	cout<<"MST\n";

	for(int i = 0; i < parent.size(); i++) {
		cout<<parent[i]<<" - "<<i<<" "<<graph[i][parent[i]]<<endl;

	}



}

int main() {
	int V; cin>>V;
	vector<vector<int> > graph(V);

	for(int i = 0; i < V; i++ ){

	 	graph[i].resize(V);
	 	for(int j = 0; j < V; j++) {
	 		cin>>graph[i][j];
	 	}

	}
	prim(graph,V);
}