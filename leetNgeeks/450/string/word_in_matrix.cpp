
// https://www.geeksforgeeks.org/search-a-word-in-a-2d-grid-of-characters/

// Search a Word in a 2D Grid of characters

#include<bits/stdc++.h>
using namespace std;



namespace my {
	vector<pair<int,int>> ans;
	int count = 0;
};

void dfs(vector<string>g,string pat) {
	///cout<<"now "<<tmp<<endl;

	int col[8] = {-1, -1, -1, 0, 0, 1, 1, 1 };
	int row[8] = {-1, 0, 1, -1, 1, -1, 0, 1 };

	int m = g.size();
	int n = g[0].length();

	int N = pat.length();

	

	for(int i = 0; i < m; i++) {

		
		for(int j = 0; j < n; j++) {

			if(pat[0] == g[i][j]) {
			
				
				for(int t = 0; t < 8; t++) {
					int xx = i + col[t];
					int yy = j + row[t];
					int k;	
		

					for(k = 1; k < N; k++) {
						
						if(xx<0 || xx>=m || yy<0 || yy>=n) {
							//cout<<"bound\n";
							break;	
						}
						if(g[xx][yy] != pat[k]){
							
							break;
						}
						xx += col[t];
						yy += row[t];
					}
					
					if(k == N) {
						my::ans.push_back({i,j});
						my::count++;
						break;
					}
					
				}

			}
		}
	}


}

int main() {
	int n;
	cin>>n;
	vector<string> g(n);
	for(int i = 0; i < n; i++) {
		cin>>g[i];
	}
	
	int ll = g[0].length();
	vector<vector<bool>> vis(n);
	for(int i = 0; i < n; i++) {
		vis[i].resize(ll);
		for(int j = 0; j < ll; j++) {
			vis[i][j]  = false;
		}
	}

	string pat; cin>>pat;

	
	dfs(g,pat);

	cout<<"count "<<my::count<<endl;

	for(auto p:my::ans) {
		cout<<p.first<<" "<<p.second<<endl;
	}


}