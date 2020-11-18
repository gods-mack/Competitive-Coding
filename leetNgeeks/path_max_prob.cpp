
// https://leetcode.com/problems/path-with-maximum-probability/

#include<bits/stdc++.h>
using namespace std;


int max_value(vector<double> dis,vector<bool>vis) {

	int max_index = -1;

	double max_val = 0.0;
	cout<<"mv "<<max_val<<endl;

	for(int i=0;i<dis.size();i++) {

		cout<<"... "<<dis[i]<<" "<<max_val<<endl;
		if(vis[i]==false and max_val < dis[i]){
			cout<<"#\n";
			max_val = dis[i];
			max_index = i;
		}
	}

	return max_index;
}


void dijkstra(vector<vector<pair<int,double>>>g,int V,int start,int end) {


	vector<double> dis(V,0.0);
	vector<bool> vis(V,false);

	dis[start] = 1.0;

	while(1) {

		int u = max_value(dis,vis);
		cout<<"u "<<u<<endl;
		if(u == -1){
			break;
		}
		vis[u] = true;

		for(int i=0;i<g[u].size();i++){
			auto p = g[u][i];
			auto v = p.first;
			double w = p.second;
			double tot = dis[u]*w;
			if(!vis[v] && tot>dis[v]){
				dis[v] = tot;
			}
		}
	}

	

	//cout<<"max prob "<<max_prob<<endl;
	for(auto x:dis){
		cout<<x<<" ";
	}
	cout<<endl;

	cout<<"max prob "<<dis[end]<<endl;
	printf("%.5lf\n", dis[end]);


}

int main() {
	
	int V,E;
	cin>>V>>E;


	vector<vector< pair<int, double> > >  g(V);


	for(int i = 0; i <E; i++) {
		int u,v;
		double w;
		cin>>u>>v>>w;
		g[u].push_back(make_pair(v,w));
		g[v].push_back(make_pair(u,w));
	}

	int start,end;
	cin>>start>>end;

	dijkstra(g,V,start,end);


}