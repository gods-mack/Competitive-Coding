

// https://leetcode.com/problems/evaluate-division/

#include<bits/stdc++.h>
using namespace std;




void dfs(map<string,vector<pair<string,double> >> &mp,set<string> vis,
		string src,string dest,double &ans,double tmp ) {


	if(vis.find(src) != vis.end()) { // if visited
		return;
	}

	vis.insert(src);

	if(src == dest) {
		ans = tmp;
		return;
	
	}


	for(auto v : mp[src]) {

		dfs(mp,vis,v.first,dest,ans,tmp*v.second);
	}

}

void calcEquation(vector<vector<string>>& equations, 
	vector<double>& values, 
	vector<vector<string>>& queries) 
{

	map<string,vector<pair<string,double>>> mp;
	for(int i = 0; i <equations.size(); i++) {
		mp[equations[i][0]].push_back({equations[i][1],values[i]});
		mp[equations[i][1]].push_back({equations[i][0],1/values[i]});	
	}


	set<string> vis;
	vector<double> ans_vec;

	for(int i = 0; i < queries.size(); i++) {

		string src = queries[i][0];
		string dest = queries[i][1];

		double ans = -1.0;

		if(mp.find(src) != mp.end()) // otherwise push -1
			dfs(mp,vis,src,dest,ans,1.0);

		ans_vec.push_back(ans);

		//cout<<src<<"/"<<dest<<" "<<ans<<endl;	
	}



}


int main() {
	int n_e; cin>>n_e; // nuber of equations
	vector<vector<string>> eqs;(n_e);
	vector<double> values(n_e);

	for(int i = 0; i <n_e; i++) {
		string x,y; cin>>x>>y;
		eqs[i].push_back(x);
		eqs[i].push_back(y);

	}


	for(int i = 0; i < n_e; i++) {
		cin>>values[i];
	}

	int n_q; cin>>n_q; //number of queries
	vector<vector<string>> queries;
	for(int i = 0; i < n_q; i++) {
		string x,y;
		cin>>x>>y;
		queries[i].push_back(x);
		queries[i].push_back(y);
	}

	calcEquation(eqs,values,queries);


}