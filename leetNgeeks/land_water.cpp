
// 1162. As Far from Land as Possible
// https://leetcode.com/problems/as-far-from-land-as-possible/

#include<bits/stdc++.h>
using namespace std;

namespace my {
int count = 0;
}





void dfs(int x,int y,vector<vector<int>>&grid){
	int n = grid.size();

	int row[8] = {1,-1,0,0,-1,1,1,-1};
	int col[8] = {0,0,1,-1,1,1,-1,-1};


	int tmp = 0;

	for(int i = 0; i < 8; i++) {
		int xx = x + row[i];
		int yy = y + col[i];


		if(xx>=0&&x<n && yy>=0 && yy<n){
			if(grid[xx][yy] = 1) {
				tmp += abs(xx-x)+abs(yy-y);
			}
		}
		if(tmp > my::count) {
			my::count = tmp;
		}
	}
} 


int maxDistance(vector<vector<int>>& grid) {
       
    int n = grid.size();

	for(int  i = 0; i  < n; i++) {

		for(int j = 0; j < n; j++) {

			if(grid[i][j]==0) {
				dfs(i,j,grid);
			}
		}
	}


	cout<<"count " <<my::count<<endl;
}

int main() {

	int n; cin>>n;
	vector<vector<int>> g(n);

	for(int i = 0; i < n; i++) {
		g[i].resize(n);
		for(int j = 0; j < n; j++){
			cin>>g[i][j];
		}
	}

	maxDistance(g);

}