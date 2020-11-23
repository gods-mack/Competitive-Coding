
// rate in maze

#include<bits/stdc++.h>

using namespace std;


namespace my {
	vector<string> ans;
}

char move_char(int i) {

	if(i == 0) {
		return 'U';
	}
	else if(i == 1) {
		return 'L';
	}
	else if(i == 2) {
		return 'R';
	}
	else{
		return 'D';
	}
}

void dfs(int x,int y,vector<vector<int>>g,string &path,vector<vector<bool>>&vis) {

	int m = g.size();
	int n = g[0].size();

	int C[4] = {-1,0,0,1};
	int R[4] = {0,-1,1,0};
	vis[x][y] = true;

	 

	if(x == m-1 and y == n-1) {
		cout<<"path "<<path<<endl;
		my::ans.push_back(path);
		//return;
	}


	for(int i = 0; i < 4; i++) {

		char move = move_char(i);
		int xx = C[i] + x;
		int yy = R[i] + y;

		if(xx>=0 && xx<m and yy>=0 and yy < n) {
			if(vis[xx][yy] == false && g[xx][yy]==1) {
				
				path += move;
				dfs(xx,yy,g,path,vis);
			}
		}


	}
	vis[x][y] = false;
	path.pop_back();




}

void print_path(vector<vector<int>> g) {


//	vector<string> ans;
	string path = "";
	int m = g.size();
	int n = g[0].size();

	vector<vector<bool> > vis(m);
	for(int i = 0; i < m; i++ ){
		vis[i].resize(n);
		for(int j = 0; j < n; j++) {
			vis[i][j] = false;
		}
	}

	dfs(0,0,g,path,vis);

	for(auto s:my::ans){
		cout<<s<<" ";
	}
	cout<<endl;

}

int main() {
	int m; cin>>m;
	int n; cin>>n;
	vector<vector<int>> g(m);
	for(int i = 0; i < m; i++) {
		g[i].resize(n);
		for(int j = 0; j < n; j++) {
			cin>>g[i][j];
		}
	}

	print_path(g);

}