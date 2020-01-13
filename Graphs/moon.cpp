
// moon journey on hackerRank

#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> graph,int u,vector<bool> &visited,vector<vector<int>>& ans,int &ind){

	if(visited[u] == false){
		visited[u] = true;
		ans[ind].push_back(u);
		for(int i = 0; i < (int)graph[u].size(); i++){
			dfs(graph,graph[u][i],visited,ans,ind);
		}
	}
}

void sol(vector<vector<int> > graph,int n,int e){

	vector<bool> visited(n);
	for(int i = 0; i < n; i++){ visited[i] = false;	}
	vector<vector<int> > ans(n);
	int ind = 0;
	for(int i = 0; i < n; i++){
		/*if(visited[i] == false and {
			ans[ind].push_back(i);
			ind++;
		}*/
		if(visited[i] == false ){
			dfs(graph,i,visited,ans,ind);
			ind++;
		}

		
	}	

	cout<<"ans \n";

	for(int i = 0; i < ans.size(); i++){
		for(int j =0; j < ans[i].size(); j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}

	cout<<"end "<<endl;
	for(int i = 0; i < ans[0].size(); i++){
		
		for(int j = 1; j < ans.size(); j++){

			for(int k = 0; k < ans[j].size(); k++){
				cout<<ans[0][i]<<" "<<ans[j][k]<<endl;
			}
		}
	}


}

int main(){
	int n; int e;
	cin>>n>>e;
	vector<vector<int> > graph(n);

	for(int i = 0; i < e; i++){
		int x; cin>>x;
		int y; cin>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	sol(graph,n,e);


}