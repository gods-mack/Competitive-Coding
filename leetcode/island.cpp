

#include<bits/stdc++.h>
using namespace std;


bool isValid(int x,int y,int n,int m){

	return (x>=0 && x < n) && (y>=0 && y < m);
}

void dfs(vector<vector<int>>&graph, int x,int y,int n,int m){

	graph[x][y] = 0;

	//int C[8] = {-1,0,1,-1,1,-1,0,1};
	//int R[8] = {-1,-1,-1,0,0,1,1,1};

	static int R[] = { -1, 0, 0, 1 };
	static int C[] = { 0, 1,-1, 0 };


	for(int i = 0; i < 4; i++){
		int xx = x + R[i];
		int yy = y + C[i];
		if(isValid(xx,yy,n,m)){

			if(graph[xx][yy] == 1){
				dfs(graph,xx,yy,n,m);
			}
		}
	}
}


void printGraph(vector<vector<int>> graph){

	int n = graph.size();
	int m  = graph[0].size();
	for(int i = 0; i < n; i++){
		
		for(int j = 0; j < m; j++){
			cout<<graph[i][j]<<" ";
		}
		cout<<endl;
	}

}
int main(){
	int n; cin>>n; // row
	int m; cin>>m; // column
	vector<vector<int>> graph(n);

	for(int i = 0; i < n; i++){
		graph[i].resize(m);
		for(int j = 0; j < m; j++){
			cin>>graph[i][j];
		}
	}

	int count = 0;
	for(int i = 0; i < n; i++){

		for(int j = 0; j < m; j++){

			if(graph[i][j] == 1){
				count++;
				dfs(graph,i,j,n, m);
				printGraph(graph);
			}
		}
	}

	cout<<"ans "<<count<<endl;
}