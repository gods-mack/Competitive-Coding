
// https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1


#include<bits/stdc++.h>
using namespace std;



int bfs(int x,int y,int t_x,int t_y,int N) {

    int C[8] = {-2,-2,-1,-1,1,1,2,2};
    int R[8] = {-1,1,-2,2,-2,2-1,1};

    int vis[N][N];
    for(int i = 0; i < N; i++) {
    	for(int j = 0; j < N; j++) {
    		vis[i][j] = false;
    	}
    }


    queue<pair<int,int> > q;

    q.push({x,y});

    int count = 0;


    while(!q.empty()) {

    	int size = q.size();
    	while(size--) {

    		pair<int,int> curr = q.front();
    		q.pop();
    		if(curr.first == t_x && curr.second==t_y) {
    			return count;
    		}
    		for(int i = 0; i < 8; i++) {
    			int xx = curr.first + C[i];
    			int yy = curr.second + R[i];

    			if(xx>=0&&xx<N && yy>=0 && yy<N) {
    				if(vis[xx][yy] != true) {
    					q.push({xx,yy});
    				}
    			}
    		}
    		
    	}
    	count++;
 
    }

   	return count;
}

void minStepToReachTarget(int k_x, int k_y,int t_x,int t_y, int N) {
    // code here

    cout<<bfs(k_x,k_y,t_x,t_y,N);
  
}

int main() {

	int k_x; // knight  X cor
	int k_y; // knight  Y cor
	cin>>k_x>>k_y;

	int t_x; // target X cor
	int t_y; // target Y cor
	cin>>t_x>>t_y;

	int N; cin>>N; // chess dimension	

	minStepToReachTarget(k_x,k_y,t_x,t_y,N);
}