
#include<bits/stdc++.h>
using namespace std;


map<string,int> hs; // flight code map

int minWeight(vector<int> &weight,vector<bool> &visited) {

	int min_ind = 0;
	int min_val = 9999; // maxx

	for(int i = 0; i < weight.size();i++) {
		if(weight[i] <= min_val && !visited[i]) {
			min_val = weight[i];
			min_ind = i;
		}
	}
	if(min_val == 9999) {
		return -1;
	}
	return min_ind;
}

void dijkstra(int *graph,int V,int src, int des){

	vector<int> weight(V);
	vector<bool> visited(V);
	vector<int> parent(V);
	
	for(int i = 0; i < V; i++){
		weight[i] = INT_MAX;
		visited[i] = false;
	}


	weight[src] = 0;
	//visited[src];

	while(1) {

		int u = minWeight(weight,visited);
		if(u == -1){
			break;
		}
		visited[u] = true;

		for(int i = 0; i < V; i++) {
			if(graph[u*V + i]!=9999 && !visited[i]) {
				
				int total = weight[u]+graph[u*V + i];
				if(total < weight[i]){
					weight[i] = total;
					parent[i] = u;
				}
				
			}
		}
	
	}


	cout<<"Weight "<<endl;
	for(int i = 0; i < V; i++)
		cout<<weight[i]<<" ";
	cout<<endl;
	cout<<"parent "<<endl;
	for(int i = 0; i < V; i++)
		cout<<parent[i]<<" ";

	cout<<"FLIGHT PATH\n";

	stack<int> path;
	int tmp = des;
	path.push(des);
	while(1) {
		 tmp = parent[tmp];
		 if(tmp == src){
		 	break;
		 }
		 path.push(hs[tmp]);

	}
	path.push(hs[src]);

	while(!path.empty()) {
		cout<<path.top()<<"->";
		path.pop();
	}
	cout<<"\n total min dis "<<weight[des]<<endl;


}

int main() {


	int V; cin>>V;
	int N; cin>>N;


	int graph[V][V];



	int m = -1;
	for(int i = 0; i < V; i++ ){
		for(int j = 0; j<V; j++){
			graph[i][j] = 9999;
		}
	}
	

	for(int i = 0; i <N; i++) {
		int x,y;
		string a;
		string b; cin>>a>>b;
		int w; cin>>w;

		if(hs.find(a) == hs.end()) {
			m++;
			hs[m] = a;
			x = m;
		}
		else{
			x = hs[a];
		}
		if(hs.find(b) == hs.end()){
			m++;
			hs[b] = m;
			y = hs[b];
		}
		else{
			y = hs[b];
		}
	
		graph[x][y] = w;
		graph[y][x] = w;

	}

	string source,desti; // src desftination
	cin>>source>>desti;

	int src = hs[source];
	int des  = hs[desti];

	dijkstra(&graph[0][0], V,src,des);
}