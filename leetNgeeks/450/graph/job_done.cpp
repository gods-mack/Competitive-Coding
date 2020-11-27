// https://www.geeksforgeeks.org/minimum-time-taken-by-each-job-to-be-completed-given-by-a-directed-acyclic-graph/

#include<bits/stdc++.h>
using namespace std;




void job_done(vector<vector<int>>&g,vector<int> &indegree) {

	int V = g.size();
	vector<int> job_time(V,0);
	queue<int> q;
	for(int i = 0; i < indegree.size(); i++) {

		if(indegree[i] == 0) {
			job_time[i] = 1;
			q.push(i);
		}
	}

	int tic = 1;
	int flag = 0;

	while(!q.empty()) {

		int size = q.size();
		while(size--) {
			if(flag==0){ // first time
				int u = q.front();
				for(int i = 0; i < g[u].size();i++){
					q.push(g[u][i]);
					job_time[g[u][i]] = 1 + job_time[u];
				}
				q.pop();

			}
		}
	}
	cout<<"anser\n";
	for(int i = 0; i < job_time.size(); i++) {
		cout<<"time for "<<i<<" is "<<job_time[i]<<endl;
	}
}


int main() {
	int V; cin>>V;
	int E; cin>>E;

	vector<vector<int> > g(V);
	vector<int> indegree(V,0);
	for(int i = 0; i < E; i++) {
		int u,v;
		cin>>u>>v;
		indegree[v]++;
		g[u].push_back(v);
	}

	for(int i= 0;i<indegree.size();i++) {
		if( indegree[i] == 0) {
			//cout<<i<<" zero inDeg\n";
		}
	}


	job_done(g,indegree);


}