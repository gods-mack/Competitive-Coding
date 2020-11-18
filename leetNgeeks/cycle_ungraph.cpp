#include<bits/stdc++.h>
using namespace std;



/* This function is used to detect a cycle in undirected graph

*  g[]: array of vectors to represent graph
*  V: number of vertices
*/
bool isCyclic(vector<int> g[], int V) {
   

	// using BFS

	v

	

}


bool find_cycle(vector<int>g[],int V, vector<int> visited,int s){

	queue<int> q;
	vector<int> visited(V,-1);
	q.push(s);
	int flag = 0;


	while(!q.empty()){
		int u = q.front();

		for(int j = 0; j < g[u].size(); j++){
			if(visited[g[u][j]] == 0){
				//cout<<"Found cycle\n";
				flag = 1;
					break;
			}
			else if(visited[g[u][j]] == -1){
				q.push(g[u][j]);
				visited[g[u][j]] = 0;
			}
		}
		if(flag){break;}

		visited[u] = 1;
		q.pop();
	}

	if(flag){return true;}
	return false;


}
   



int main() {
	int T;
  cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;
        
        // array of vectors to represent graph
        vector<int> adj[V];
        
        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            
            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V)<<endl;

    }
}