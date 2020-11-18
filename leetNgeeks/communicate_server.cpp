
// https://leetcode.com/problems/count-servers-that-communicate/

#include<bits/stdc++.h>
using namespace std;


int count_server(vector<vector<int>>&grid ) {


	int n = grid.size();
	int m = grid[0].size();

	int row[n] = {0};
	int col[m] = {0};

	for(int i = 0; i < n; i++) {

		for(int j = 0; j < m; j++) {
			if(grid[i][j] == 1) {
				row[i]++;
				col[j]++;
			}
		}
	}

	int count = 0;

	for(int i = 0; i <n; i++){
		for(int j = 0;j < m; j++) {
			if(grid[i][j] && (col[j]>1 or row[i]>1)){
				count++;
			}
		}
	} 

	return count;
}

int main() {
	int n; cin>>n;
	int m; cin>>m;


	vector<vector<int>> g(n);

	for(int i = 0; i < n; i++) {
		g.resize(m);
		for(int j = 0; j < m; j++) {
			cin>>g[i][j];
		}
	}


}