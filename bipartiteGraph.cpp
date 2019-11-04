
// find a graph bipartite or not
#include<bits/stdc++.h>
using namespace std;


void bipartite(vector<vector<int>> graph, int V){
	queue<int> q;
	char color[V]; for(int i = 0; i < V; i++) { color[i] = 'N';} // color array 
	q.push(0);
	color[0] = 'R'; // first vertex

	while(!q.empty()){
		int frnt = q.front();
		char clr = color[frnt];
		for(int i = 0; i < graph[frnt].size(); i++){
			if(color[graph[frnt][i]] == 'N'){
				if(clr == 'R'){ color[graph[frnt][i]] = 'B';}
				else{ color[graph[frnt][i]] = 'R'; }
				q.push(graph[frnt][i]);
			}
		}
		q.pop();
	}	

	cout<<"color arary"<<endl;
	for(int i = 0; i < V; i++){
		cout<<color[i]<<" ";
	}

	int flag  = 1;
	for(int i = 0; i < V; i++){
		for(int j = 0; j < graph[i].size(); j++){
			if(color[i] == color[graph[i][j]]){ // adject edge has same color Break
				cout<<"\nnot bipartite\n";
				flag = 0;
				break;
			}
		}
		if(flag == 0){ break;}
	}

	if(flag ==1){ cout<<"\nYes bipaartite"; }
}


int main(){
	int V; cin>>V;
	int E; cin>>E;
	vector<vector<int> > graph(V);
	for(int i = 0; i < E; i++){
		int x; cin>>x;
		int y; cin>>y;
		graph[x-1].push_back(y-1);
		graph[y-1].push_back(x-1);
	}

	bipartite(graph,V);
}