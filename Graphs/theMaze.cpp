
//search in maze by DFS

#include<bits/stdc++.h>
using namespace std;



bool isSafe(vector<vector<int>> maze, int x, int y,vector<vector<bool>> visited){
	int N = maze[0].size();
	
	if(x>=0 and x<N and y>=0 and y<N and (maze[x][y] == 1 or maze[x][y] == 9)){
		return !visited[x][y];
	}
	else{
		return false;
	}
}

void printPath(stack<pair<int, int> > stk){
	while(!stk.empty()){
		auto p = stk.top();
		stk.pop();
		cout<<p.first<<" "<<p.second<<endl;
	}
}


void solveMaze(vector<vector<int>> maze, int N){

	cout<<"enter start pos\n";
	int f; int g; cin>>f>>g;



	vector<vector<bool>> visited(N);
	for(int i = 0; i < N; i++){
		visited[i].resize(N);
		for(int j = 0; j < N; j++){
			visited[i][j] = false;
		}
	}
	visited[f][g] = true;

	stack<pair<int,int>> stk;
	stk.push({f,g});

	vector<int> colN = {-1,0,0,1};
	vector<int> rowN = {0,-1,1,0};

	while(!stk.empty()){

		auto tmp  = stk.top();

		int tmpFlag = 1;
		int endFlag = 0;
		for(int i = 0; i < 4; i++){
			

			int xx = tmp.first+colN[i];
			int yy = tmp.second+rowN[i];
			

			if(isSafe(maze, xx, yy, visited) ){
				//cout<<"its safe "<<xx<<" "<<yy<<endl;
				tmpFlag = 0;
				stk.push({xx,yy});
				visited[xx][yy] = true;
				if(maze[xx][yy] == 9){
					endFlag = 1;
					break;
				}
				break;  // if safe find just deep dig in this cuurent
			}
		}
		if(tmpFlag == 1){
			stk.pop();
		}
		if(endFlag == 1){
			printPath(stk);
			break;

		}

	}

}

int main(){
	int N;
	cin>>N;
	vector<vector<int> > maze(N);

	for(int i = 0; i < N; i++){
		maze[i].resize(N);
		for(int j = 0; j < N; j++){
			int x; cin>>x;
			maze[i][j] = x;
		}
	}

	solveMaze(maze,N);




}