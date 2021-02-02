

#include<bits/stdc++.h>
using namespace std;


void demo(	vector<vector<int>> g, int m,int n){

	queue<pair<int,int>> q;


	int t = 0;
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++){
			if(g[i][j] == 2) {
				cout<<i<<" "<<j<<endl;
				q.push({i,j});
			}
		}
	}

	while(!q.empty()) {
		
		int size = q.size();

		while(size--) {
			auto p = q.front();
			q.pop();
			int x = p.first;
			int y = p.second;
			if(x-1>=0 ){
				if(g[x-1][y]==1 and g[x-1][y]!=0){
					q.push({x-1,y});
					g[x-1][y] = 2;
				}
			}
			if(x+1<m ){
				if(g[x+1][y]==1 and g[x+1][y]!=0){
					q.push({x+1,y});
					g[x+1][y] = 2;
				}
			}
			if( y-1>=0){
				if(g[x][y-1]==1 and g[x][y-1]!=0){
					q.push({x,y-1});
					g[x][y-1] = 2;
				}
				
			}
			if( y+1<n){
				if(g[x][y+1]==1 and g[x][y+1]!=0){
					q.push({x,y+1});
					g[x][y+1] = 2;
				}
				
			}

		}
		t++;
	}

	cout<<"time "<<t<<endl;
}

int main() {
	int m; cin>>m;
	int n; cin>>n;
	vector<vector<int>> g(m);

	for(int i = 0; i < m; i++) {
		g[i].resize(n);
		for(int j = 0; j < n; j++){
			cin>>g[i][j];
		}
	}

	demo(g,m,n);
}