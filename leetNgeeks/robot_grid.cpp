

#include<bits/stdc++.h>
using namespace std;

struct path {
	int x; int y;
};

vector<path> u_path;

int sol_recur(vector<vector<int>> grid,int x,int y) {
	if(x >= grid.size() or x<0){
		return 0;
	}
	if(y >= grid[0].size() or y <0){
		return 0;
	}

	if(grid[x][y]==2){
		return 0;
	}
	u_path.push_back({x,y});

	if(grid[x][y]==7){
		cout<<"###\n";
		
		return 1;
	}


	if(sol_recur(grid,x+1,y) or sol_recur(grid,x,y+1)){
		return 1;
	}
	u_path.pop_back();
}




void dfs_sol(vector<vector<int>>grid) {

	int m = grid.size();
	int n = grid[0].size();
	stack<pair<int,int>> st;
	st.push({0,0});
	bool visited[m][n];
	memset(visited,false,sizeof(visited));

	vector<path> t_path;
	t_path.push_back({0,0});

	while(!st.empty()) {
		int cx = st.top().first;
		int cy = st.top().second;
		st.pop();
	
		int f = 1;

		// go DOWN
		if(cx+1<m and cx+1>=0){
			if(cx+1==m-1 and cy==n-1){
				t_path.push_back({cx+1,cy});
				break;
			}
			if(!visited[cx+1][cy] and grid[cx+1][cy]==1) {
				t_path.push_back({cx+1,cy});
				st.push({cx+1,cy});
				visited[cx+1][cy] = true;
				f = 0;
			}

		}

		// go RIGHT
		if(cy+1<n and cy>=0){
			if(cx==m-1 and cy+1==n-1){
				t_path.push_back({cx,cy+1});
				//st.push({cx,cy+1});
				break;
			}
			if(!visited[cx][cy+1]and grid[cx][cy+1]==1){
				t_path.push_back({cx,cy+1});
				st.push({cx,cy+1});
				visited[cx][cy+1] = true;
				f = 0;
			}
		}
		if(f == 1){
			t_path.pop_back();
		}
	}

	cout<<"PATH STACK\n";
	/*while(!st.empty()) {
		cout<<st.top().first<<" "<<st.top().second<<endl;
		st.pop();
	}*/
	for(int i = 0; i < t_path.size(); i++) {
		cout<<t_path[i].x<<" "<<t_path[i].y<<endl;

	}
}	

int main() {
	int m; cin>>m;
	int n; cin>>n;

	vector<vector<int>> grid(m);
	for(int i=0;i<m;i++){
		grid[i].resize(n);
		for(int j=0;j<n;j++){
			cin>>grid[i][j];
		}
	}
	sol_recur(grid,0,0);
	cout<<"path "<<endl;
	for(int i = 0; i < u_path.size(); i++) {
		cout<<u_path[i].x<<" "<<u_path[i].y<<endl;

	}
	cout<<endl;

	dfs_sol(grid);


}