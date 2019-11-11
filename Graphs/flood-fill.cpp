
// flood fill algorithm

#define ll long long
#include<bits/stdc++.h>
using namespace std;

bool isValid(vector <vector <int> > v, int x, int y) {
    if(x >= v.size() || x < 0)
        return false;
    if(y >= v[0].size() || y < 0)
        return false;
    return true;
}

int corX[4] = {1, -1, 0, 0};
int corY[4] = {0, 0, 1, -1};

int main()
 {
	int t, n, m, x, y, k;
	cin >> t;
	while(t--) {
	    cin >> n >> m;
	    vector <vector <int> > v(n, vector <int> (m, 0));
	    for(int i = 0; i < n; i++) {
	        for(int j = 0; j < m; j++)
	            cin >> v[i][j];
	    }
	    
	    cin >> x >> y >> k;
	    stack < pair<int,int> > s;
	    s.push({x, y});
	    int old_color = v[x][y];
	    v[x][y] = k;
	    while(!s.empty()) {
	        auto p = s.top();
	        s.pop();
	        
	        for(int i = 0; i < 4; i++) {
	            int xx = p.first + corX[i];
	            int yy = p.second + corY[i];
	            if(isValid(v, xx, yy) && v[xx][yy] == old_color){
	                v[xx][yy] = k;
	                s.push({xx, yy});
	            }
	        }
	    }
	    
	    for(int i = 0; i < n; i++) {
	        for(int j = 0; j < m; j++)
	            cout << v[i][j] << " ";
	       	cout<<endl; 
	 
	    }
	    cout << endl;
	}
	return 0;
}