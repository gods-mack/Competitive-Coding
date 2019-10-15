/*

Min Cost Path | DP-6

Given a cost matrix cost[][] and a position (m, n) in cost[][], 
write a function that returns cost of minimum cost path to reach (m, n) from (0, 0). 
Each cell of the matrix represents a cost to traverse through that cell. Total cost of a 
path to reach (m, n) is sum of all the costs on that path (including both source and destination).
ou can only traverse down, right and diagonally lower cells from a given cell, i.e., from a given 
ell (i, j), cells (i+1, j), (i, j+1) and (i+1, j+1) can be traversed. 
You may assume that all costs are positive integers.

*/

#include<bits/stdc++.h>
using namespace std;



// Top Down  solution
int minPathSum(vector<vector<int> > grid, int x, int y, int N){

	if(x>N or  y>N){
		return INT_MAX;

	}
	else if(x==N and y==N){
		//cout<<"tha pe "<<grid[x][y]<<endl;
		return grid[x][y];

	}
	else{
		return grid[x][y] + min(min(minPathSum(grid,x+1,y,N),minPathSum(grid,x,y+1,N)),minPathSum(grid,x+1,y+1,N));
	}
}

// bottom up
int bottomUp(vector<vector<int> > grid,  int N){
	int memo[N][N];
	memo[0][0] = grid[0][0];

	for(int i = 1; i < N; i++){ // intialize first row
		memo[0][i] = grid[0][i] + memo[0][i-1];
	}

	for(int i = 1; i < N; i++){ // intialize first column
		memo[i][0] = grid[i][0] + memo[i-1][0];
	}

	for(int i = 1; i < N; i++){
		for(int j = 1; j  < N; j++){
			memo[i][j] = grid[i][j] +  min(min(memo[i-1][j],memo[i][j-1]),memo[i-1][j-1]);
		}
	}

	return memo[N-1][N-1];


}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<vector<int> > grid(n);
		for(int i = 0; i < n; i++){
			vector<int> tmp;
			for(int j = 0; j < n; j++ ){
				int x;
				cin>>x;
				tmp.push_back(x);
			}
			grid[i] = tmp;
		}
		cout<<"cost "<<minPathSum(grid,0,0,n-1)<<endl;
		cout<<"cost bottom up "<<bottomUp(grid,n)<<endl;
	}
}