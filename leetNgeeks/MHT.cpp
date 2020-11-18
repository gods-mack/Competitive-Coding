
// minimum height trees

// https://leetcode.com/problems/minimum-height-trees/

#include<bits/stdc++.h>
using namespace std;


    
    int mht(int src, vector<vector<int> > graph,int V) {


	vector<bool> vis;
    for(int i = 0; i < V; i++) {
        vis.push_back(false);
    }
	queue<int> q;
	q.push(src);

	int count = -1 ;


	while(!q.empty()) {

        
	    for(int j = 0; j < q.size(); j++)
    	 {
			int curr = q.front();
			vis[curr] = true;
			q.pop();
			for(int i = 0; i < graph[curr].size(); i++) {
			if(!vis[graph[curr][i]])
				q.push(graph[curr][i]);
			}

		}
		count++;
	}

    return count;    
}
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) { 
      
        vector<int> ans;
        if(n == 0){
            return ans;
        }
        
        //map<int,vector<int>> hs;
      int   h = INT_MAX;
        
        for(int i = 0; i < n; i++) {
         int curr = mht(i,edges,n);
            if(curr == h){
                ans.push_back(i);
            }
            else if(curr < h) {
                h = curr;
                ans.clear();
                ans.push_back(i);
            }
          //  hs[h].push_back(i);
            
        }
        
        ///auto it = hs.begin();
        
      //  auto ans1 = it->second;
      //  for(int i = 0; i < ans1.size(); i++){
     //       ans.push_back(ans1[i]);
       // }
            
       // ans =  it->second;
        return ans;
            
    }


void mht_brute(int src, vector<vector<int>> &graph,int V) {


	vector<bool> vis(V,false);
	queue<int> q;
	q.push(src);

	int count = -1 ;


	while(!q.empty()) {

		/*int u = q.front();
		cout<<"u "<<u<<endl;
		vis[u] = true;
		//q.pop();
		*/
		int  sze = q.size();
	
		while(sze--) {
			int curr = q.front();
			vis[curr] = true;
			q.pop();
			for(int i = 0; i < graph[curr].size(); i++) {
			if(!vis[graph[curr][i]])
				q.push(graph[curr][i]);
			}

		}
		count++;
	}

	cout<<"src "<<src<<" mht "<<count<<endl;
}



void mht(vector<vector<int>> graph,int V,vector<int> degree) {


	queue<int> q;
	for(int i = 0; i < degree.size(); i++) {
		if(degree[i]==1) { // store all leaf node
			q.push(i);
		}
	}

	while(V > 2) {

		int sze = q.size();
		while(sze--) {	
			int curr = q.front();
			q.pop();
			V--;

			for(int i = 0; i < graph[curr].size();i++){

				degree[graph[curr][i]]--;

				if(degree[graph[curr][i]] == 1){
					q.push(graph[curr][i]);
				}
			}
		}
	}


	while(!q.empty()){
		cout<<q.front()<<endl;
		q.pop();
	}	
}


int main() {

	int V; cin>>V;
	int E;cin>>E;
	vector<vector<int>> graph(V);

	vector<int> degree(V);

	for(int i = 0; i < E; i++) {
		int x,y;
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
		degree[x]++;
		degree[y]++;
	}


	//** brute force in N^2
	/*for(int  i = 0; i < V; i++) {
		mht_brute(i,graph,V);
	}*/

	vector<int> ans = findMinHeightTrees(V,graph);
	/// **

	for(auto x:ans){
		cout<<x<<" ";
	}

	//cout<<"effient sol in O(n)\n";
	//mht(graph,V,degree);



}