
// leetcode 130. Surroded Region DFS
// https://leetcode.com/problems/surrounded-regions/

#include<bits/stdc++.h>
using namespace std;




void dfs(int x,int y,vector<vector<char>> &g) {


	
	int m = g.size();
	int n = g[0].size();
	g[x][y] = 'Y';
	
	int col[4] = {0,-1,1,0};
	int row[4] = {-1,0,0,1};
	

	for(int i = 0; i < 4; i++) {

		int xx = x+col[i];
		int yy = y+row[i];
		if(xx>=0 && xx<m && yy>=0 && yy<n && g[xx][yy]=='O' ){
			dfs(xx,yy,g);
		}
	}


}

void solve(vector<vector<char>>& board) {

	if (board.size()==0 || board[0].size()==0) return;
    
    int m = board.size();
    int n = board[0].size();
   
	



	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if(i==0 or i==m-1 or j==0 or j==n-1) {
				if(board[i][j] == 'O')
					dfs(i,j,board);
			}
		}	
	}

	for(int i = 0; i < m; i++) {
		
		for(int j = 0; j < n; j++) {
			if(board[i][j] == 'O'){
				board[i][j] = 'X';
			}
			if(board[i][j] == 'Y'){ // not possible
				board[i][j] = 'O';
			}
		}
	}



}

int main() {

	int n; cin>>n;
	vector<vector<char> > g(n);

	for(int i = 0; i < n; i++) {
		g[i].resize(n);
		for(int j = 0; j < n; j++) {
			cin>>g[i][j];
		}
	}

	solve(g);

	cout<<"###\n";

	for(int i = 0; i < n; i++) {
		//g[i].resize(n);
		for(int j = 0; j < n; j++) {
			cout<<g[i][j];
		}
		cout<<endl;
	}



}