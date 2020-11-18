
// non-cyclic graph diameter (DAG)

#include<bits/stdc++.h>
using namespace std;

vector<int> diameter_helper(vector<vector<int>> &graph,int V,int src) {

	vector<bool> vis(V,false);
	vector<int> dis(V,-1);

	queue<int> q;
	q.push(src);
	dis[src] = 0;

	while(!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = true;

		for(int i = 0; i < graph[u].size(); i++) {

			if(!vis[graph[u][i]]) {

				dis[graph[u][i]] = dis[u] + 1;
				q.push(graph[u][i]);
			}
		}
	}

	

	return dis;
}

void diameter(vector<vector<int>> graph,int V) {

	vector<int> dis1 = diameter_helper(graph,V,0);
	int maxx1 = INT_MIN;
	int m_ind1;
	for(int i = 0; i<V; i++) {
		if(dis1[i] > maxx1) {
			maxx1 = dis1[i];
			m_ind1 = i;
		}
	}
	//cout<<"maxx1 "<<maxx1<<endl;

	vector<int> dis2 = diameter_helper(graph,V,m_ind1);

	int maxx2 = INT_MIN;
	int m_ind2;
	for(int i = 0; i<V; i++) {
		if(dis2[i] > maxx2) {
			maxx2 = dis2[i];
			m_ind2 = i;
		}
	}

	cout<<"length "<<maxx2<<endl;
	cout<<"from to "<<m_ind2<<" "<<m_ind1<<endl;



}

int main() {
	int V; cin>>V;
	int E; cin>>E;

	vector<vector<int>> graph(V);
	for(int i = 0; i < E; i++) {
		int x; cin>>x;
		int y; cin>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	diameter(graph,V);
}