

#include<bits/stdc++.h>
using namespace std;


bool isValid(int x,int y,int m,int n) {
	cout<<"asking for "<<x<<" "<<y<<endl;	

	return (x>=0 && x<m) && (y>=0 && y<m) ;
}


void DFS(vector<vector<int>>&grid,vector<vector<bool>>&vis,int x,int y) {

	cout<<"...."<<endl;
	int m = grid.size();
	int n = grid[0].size();
	static int rowNbr[] = { -1, -1, -1, 0, 0, 1, 1, 1 }; 
    static int colNbr[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

    vis[x][y] = true;
	

		for(int k = 0; k < 8; k++) {
			
			if(isValid(x+rowNbr[k],y+colNbr[k],m,n)){
				if(!grid[x+rowNbr[k]][y+colNbr[k]]) {
					continue;
				}
				if(!vis[x+rowNbr[k]][y+rowNbr[k]]) {
					DFS(grid,vis,x+rowNbr[k],y+colNbr[k]);
				}

			}
		}
	
}




int main() {
	int t; cin>>t;
	while(t--) {
		int m; cin>>m;
		int n; cin>>n;
		vector<vector<int> > grid(m);
		vector<vector<bool> > visited(m);

		for(int i = 0; i < m; i++) {
			grid[i].resize(n);
			visited[i].resize(n);
			for(int j = 0; j < n; j++) {
				cin>>grid[i][j];
				visited[i][j] = false;
			}
		}


		int count = 0;

		for(int i = 0; i < m; i++) {
		
			for(int j = 0; j < n; j++) {
				cout<<"iter.."<<endl;
				if(grid[i][j]==1 && !visited[i][j]) {
					DFS(grid,visited,i,j);
					count++;

				}
			}
		}

		cout<<"islands: "<<count<<endl;

	}
}