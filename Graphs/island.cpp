
/*
A group of connected 1's forms an island. The task is 
to complete the method findIslands() which returns the number of islands present. 
The function takes three arguments the first is the boolean matrix A and then the 
next two arguments are N and M denoting the size(N*M) of the matrix A . 

Input
2
3 3
1 1 0 0 0 1 1 0 1
4 4
1 1 0 0 0 0 1 0 0 0 0 1 0 1 0 0

Output
2
2

*/


#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int> > graph,vector<vector<bool>> visited, int x, int y){

	int col = graph.size();
	int row = graph[0].size();

	return (x>=0 and x < row) and (y>=0 and y<col) and  visited[x][y]==false and graph[x][y]==1;
}

void DFS(vector<vector<int> > graph, int x, int y,vector<vector<bool> > &visited){

	int col = graph.size();
	int row = graph[0].size();
	//cout<<col<<" "<<row<<" this size "<<endl;
	 // These arrays are used to get 
    // row and column numbers of 8 
    // neighbours of a given cell 
    static int rowNbr[] = { -1, -1, -1, 0, 0, 1, 1, 1 }; 
    static int colNbr[] = { -1, 0, 1, -1, 1, -1, 0, 1 }; 
    visited[x][y] = true;

    for(int k  = 0; k < 8 ; k++){
    	if(isSafe(graph,visited,x+rowNbr[k],y+colNbr[k])){
    		DFS(graph,x+rowNbr[k],y+colNbr[k],visited);
    	}
    }

}

void countIsland(vector<vector<int> > graph, int row, int col ){

	vector<vector<bool> > visited(row);
	for(int i = 0; i < row; i++){
		visited[i].resize(col);
		for(int j = 0; j < col; j++){
			visited[i][j] = false;
		}
	} 

	int count = 0;
	for(int i = 0; i  < row; i++){
		for(int j = 0; j < col; j++){
			if(graph[i][j] == 1 and visited[i][j] == false){
				DFS(graph,i,j,visited);
				count++;
			}
		}
	}
	cout<<"count " <<count<<endl;
}

int main(){
	int r; cin>>r;
	int c; cin>>c;
	vector<vector<int> > graph(r);
	for(int i = 0; i < r; i++){
		graph[i].resize(c);
		for(int j = 0; j < c; j++){
			int el; cin>>el;
			graph[i][j] = el;
		}
	}
	


	countIsland(graph,r,c);


}