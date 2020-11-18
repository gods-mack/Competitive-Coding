




#include<bits/stdc++.h>
using namespace std;


void bipartite(vector<vector<int>> graph,int V) {

	vector<int> color(V,-1); 
	// 0 -> Blue
	// 1 -> Red
	// -1 -> no color

	color[0] = 1;

	for(int i = 0; i < V; i++) {

		for(int j = 0; j < graph[i].size(); j++) {

			if(color[graph[i][j]] == -1){
				color[graph[i][j]] = 1-color[i];
			}
			else if(color[graph[i][j]] == color[i]){
				return false;
			}

		}
	}

	return true;

}


int main() {

	int V; cin>>V;
	int E; cin>>E;
	vector<vector<int>> graph(V);
	for(int i = 0; i < E; i++) {
		int x,y;
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}



/*
if(clr == 1){

				if(color[graph[u][i]] == clr){
					flag = 1;
					break;
				}
				else{
					if(color[graph[u][i]] == 0){
						color[graph[u][i]] = 2;
					}
					q.push(graph[u][i]);
				}
			}
			else{

				if(color[graph[u][i]] == clr){
					flag = 1;
					break;
				}
				else{
					if(color[graph[u][i]] == 0){
						color[graph[u][i]] = 1;
					}
					q.push(graph[u][i]);
				}
			}
		}
		if(flag) {
			break;
		}

		*/