
/*

Given a 2D grid, each cell is either a zombie 1 or a human 0. 
Zombies can turn adjacent (up/down/left/right) human beings 
into zombies every hour. Find out 
how many hours does it take to infect all humans?

*/

#include<bits/stdc++.h>
using namespace std;

int isValid(int x,int y,int n,int m){
	if((x<n and x>-1) and (y<m and y>-1)){
		return 1;
	}
	return 0;
}

void sol(vector<int>grid[],int n,int m){

	queue<pair<int,int>> q;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(grid[i][j]==1){
				q.push({i,j});	
				//cout<<i<<" "<<j<<endl;0 
			}
		}
	}
	int time=0;
	while(!q.empty()){
		int flag=1;
		int size=q.size();
		//cout<<"qsize "<<size<<endl;
		while(size--){
			pair<int,int>tmp = q.front();
			q.pop();
			int x=tmp.first;
			int y=tmp.second;
			//cout<<"check.."<<x<<" "<<y<<endl;

			int R[4] = {0,-1,1,0};
			int C[4] = {-1,0,0,1};

			for(int i=0;i<4;i++){
				if(isValid(x+R[i],y+C[i],n,m)){
					if(!grid[x+R[i]][y+C[i]]){
						flag=0;
						grid[x+R[i]][y+C[i]] = 1;
						q.push({x+R[i],y+C[i]});
					}
				}
			}
		}
		if(flag){break;}
		time++;
	}

	cout<<"time "<<time<<endl;
}

int main(){
	int n; cin>>n;
	int m; cin>>m;
	vector<int> grid[n];
	for(int i=0; i < n; i++){
		grid[i].resize(m);
		for(int j=0;j<m;j++){
			cin>>grid[i][j];  // 1->zombie, 0->human
		}

	}
	
	sol(grid,n,m);
	
}