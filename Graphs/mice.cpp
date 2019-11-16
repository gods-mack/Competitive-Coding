/*

 a mouse is in maze his intial postion is [0][0] and there is a candy in
 maze you have to find can mouse get this candy . candy is represented by 9
 in maze cell 1 is showing there is path and 0 showing there is wall.

 */

#include<bits/stdc++.h>
#include<cstdio>
using namespace std;


int isSafe(int x, int y, int m , int n,vector<vector<int>> &visited){
	return (x>=0 and x<m) and (y>=0 and y<n) and !visited[x][y];
}

int sol(vector<vector<int> > &grid, int m, int n){


	vector<vector<int> > visited(m);
	for(int i = 0; i < m; i++){
		visited[i].resize(n);
		for(int j = 0; j < n; j++){
			visited[i][j] = 0;
		}
	}

	stack<pair<int,int>> st;
	st.push({0,0});

	int colN[4] = {-1,0,0,1};
	int rowN[4] = {0,-1,1,0};

	while(!st.empty()){
		auto p = st.top();
		st.pop();

		int x = p.first;
		int y = p.second;
		visited[x][y] = 1; // mamke it visited

		

		for(int i = 0; i < 4; i++){
			int xx = p.first + colN[i];
			int yy = p.second + rowN[i];
			

			if(isSafe(xx,yy,m,n,visited) and (grid[xx][yy]==1 or grid[xx][yy] == 9)){
				
				if(grid[xx][yy] == 9){
					cout<<"got candy"<<endl;
					return 1;
				}
				st.push({xx,yy});
			}
		}

		
	}

	return 0;
}


int main(){
	int m; int n;
	cin>>m>>n;
	vector<vector<int> > grid(m);
	for(int i = 0; i < m; i++){
		grid[i].resize(n);
		for(int j = 0; j < n; j++){
			cin>>grid[i][j];
		}
	}

	
	cout<<sol(grid,m,n);


}