 // prim's algorithm

#include<bits/stdc++.h>
using namespace std;


int minKey(vector< unsigned int> &key, vector<bool> &visit){
	int miN  = INT_MAX, min_index;
	for(int i = 0; i  < (int)key.size(); i++){
		if(key[i] < miN and visit[i]== false){
			miN = key[i];
			min_index = i;
		}
	}

	return min_index;
}


void printMST(vector<int> mst){
	cout<<"Minimum spaning tree\n";
	for(int i = 1; i < (int)mst.size(); i++){
		cout<<mst[i]<<" - "<<i<<" ";
	}
}

void MST(vector<vector<pair<int, unsigned int> > > edge,int V, int E){
	vector<unsigned int> key(V);
	vector<bool> visit(V);
	vector<int> ans(V);  // MSTset array
	for(int i = 0; i < V; i++){  // assign all with false
		visit[i] = false;
		key[i] = INT_MAX;
	}
	
	key[0] = 0;
	ans[0] = -1;

	for(int i = 0 ; i < V -1; i++){
		int u = minKey(key,visit);
		visit[u] = true;	

		for(int j = 0; j < (int)edge[u].size();  j++){
			pair<int, int> edg = edge[u][j];
			if(edg.first and visit[edg.first]==false and edg.second < key[edg.first]){
				key[edg.first] = edg.second;
				ans[edg.first] = u;
			}
		}
	}

	printMST(ans);

}


int main(){
	int V,E;
	cin>>V>>E;
	vector< vector<pair<int, unsigned int> > > edge(V);
	for(int i = 0; i < E; i++){
		int x,y,w;
		cin>>x>>y>>w;
		edge[x].push_back(make_pair(y,w));
		edge[y].push_back(make_pair(x,w));
	}
	MST(edge, V, E);
} 