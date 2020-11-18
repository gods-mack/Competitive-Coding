

// https://leetcode.com/problems/find-eventual-safe-states/


#include<bits/stdc++.h>
using namespace std;


void isCycle(vector<vector<int>> graph,int u,vector<int>&vis) {

	vis[u] = 1;


	for(int i  = 0; i < graph[u].size(); i++) {

		if(vis[graph[u][i]] == 1) {
			
			return true;
		}
		else if(vis[graph[u][i]] != 2) {;
			if(isCycle(graph,graph[u][i],vis))
				return true;
		}
	}

	vis[u] = 2;

	return false;

}

int main() {

	int V; cin>>V;
	int E; cin>>E;
	vector<vector<int>> graph(V);
	for(int i = 0; i < E; i++) {
		int x,y;
		cin>>x>>y;
		graph[x].push_back(y);
	}



	vector<int> visited(V,0);
	for(int i = 0; i < V; i++) {
		
		if(!isCycle(graph,i,visited,parent)){
			ans.push_back(i);
		}
		
	}

	vector<int> ans;
	cout<<"parent\n";
	for(auto p : parent) {
		cout<<p<<" ";
	}
	

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