
// moon journey on hackerRank

/*\
 The member states of the UN are planning to send
 2 people to the moon. They want them to be from different countries.
 You will be given a list of pairs of astronaut ID's. 
 Each pair is made of astronauts from the same country. Determine how many pairs of astronauts from different countries they can choose from.


For example, we have the following data on 2 pairs of astronauts,
 and 4 astronauts total, numbered 0 to 3
through 

input: 
1   2
2   3

explanation : 

Astronauts by country are [0] and [1,2,3] There are 3 pairs to 
choose from: [0,1],[0,2] and [0,3]




*/

#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> graph,int u,vector<bool> &visited,vector<vector<int>>& ans,int &ind){

	if(visited[u] == false){
		visited[u] = true;
		ans[ind].push_back(u);
		for(int i = 0; i < (int)graph[u].size(); i++){
			dfs(graph,graph[u][i],visited,ans,ind);
		}
	}
}

void sol(vector<vector<int> > graph,int n,int e){

	vector<bool> visited(n);
	for(int i = 0; i < n; i++){ visited[i] = false;	}
	vector<vector<int> > ans(n);
	int ind = 0;
	int res = 0;
	int sum = 0;

	for(int i = 0; i < n; i++){
		/*if(visited[i] == false and {
			ans[ind].push_back(i);
			ind++;
		}*/
		if(visited[i] == false ){
			dfs(graph,i,visited,ans,ind);
			int size = ans[ind].size();
			res = res + (sum*size);
			sum  = sum + size;
			ind++;
		}

		
	}	

	cout<<"answer "<<res<<endl;

	cout<<"all connected pairs\n";

	for(int i = 0; i < ans.size(); i++){
		for(int j =0; j < ans[i].size(); j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}

	

}

int main(){
	int n; int e;
	cin>>n>>e;
	vector<vector<int> > graph(n);

	for(int i = 0; i < e; i++){
		int x; cin>>x;
		int y; cin>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	sol(graph,n,e);


}