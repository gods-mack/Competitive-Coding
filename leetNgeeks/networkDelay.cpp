
// Network Delay time
// https://leetcode.com/problems/network-delay-time/

#include<bits/stdc++.h>
using namespace std;


 int min_Key(vector<int>&d,vector<int>&vis) {
        int min_index = -1;
        int min_val = INT_MAX;
        for(int i = 0; i < d.size(); i++) {
            if(!vis[i] and d[i] < min_val) {
                min_val = d[i];
                min_index = i;
            }
        }
        
        return min_index;
    }

void networkDelayTime(vector<vector<int>>& times, int N, int K) {
        
 vector<vector<pair<int,int>> > graph(N+1);
 	for(auto vec:times) {
 		pair<int,int> p;
 		p.first = vec[1];
 		p.second = vec[2];
 		graph[vec[0]].push_back(p);
 	} 

 	vector<int> dis(N+1,INT_MAX);
 	vector<int> vis(N+1,false);
 	dis[K] = 0;

 
 	while(1) {
        int u = min_Key(dis,vis);
        cout<<"mingot "<<u<<endl;
        if(u == -1){
            break;
        }
        
        vis[u] = true;
        
        for(int i = 0; i < graph[u].size(); i++) {
            
            	auto p = graph[u][i];
                if(!vis[p.first] && dis[p.first]>dis[u]+p.second){
                    dis[p.first] = dis[u]+p.second;
                }
            
            
        }
    }
    int ans = -1;

    for(auto x:dis){
    	if(x != INT_MAX){
    		if(ans < x){
    			ans = x;
    		}
    	}
    }
    cout<<endl;
        
        //int ans = *max_element(dis.begin(),dis.end());

        
        cout<<"ans "<<ans<<endl;
 	

 }

int main() {

	int V; cin>>V;
	int E; cin>>E;
	vector<vector<int>> edges(E);
	for(int i = 0; i < E; i++) {
		int u,v,w;
		cin>>u>>v>>w;
		edges[i].push_back(u);
		edges[i].push_back(v);
		edges[i].push_back(w);
	}
	int K; cin>>K;

	networkDelayTime(edges,V,K);
}


/*
	vector<int> max_wt(N+1);
 	int m = 1;
 	for(int i = 1; i < graph.size(); i++){
 		int tmp = -1;
 		for(int j = 0; j < graph[i].size();j++){
 			pair<int,int> p = graph[i][j];
 			//cout<<"p "<<p.first<<" "<<p.second<<endl;
 			if(tmp < p.second) {
 				tmp = p.second;
 			}
 		}
 		max_wt[i] =tmp;
 	}
 	
 
 	queue<int> q;
 	//priority()
 	q.push(K);
 	vector<int> vis(N+1,0);
 	vector<int> dis(N+1,0);
 	int count = 0;
 	set<int> st;
 	st.insert(K);
 	set<int> ch;
 	ch.insert(K);


 	while(!q.empty()) {

 		int sze = q.size();
 		while(sze--) {
 			int u = q.front();
 			cout<<"u " <<u<<" "<<max_wt[u]<<endl;
 			vis[u] = true;
 			
 			q.pop();
 			int f = 0;

 			for(int i =0; i < graph[u].size(); i++) {
 				pair<int,int> p = graph[u][i];
 				dis[p.first] = p.second;
 				if(!vis[p.first]){
 					if(graph[p.first].size()==0){
 						vis[p.first] = true;
 					}

 					f = 1;
 					ch.insert(p.first);
 					st.insert(p.first);
 					q.push(p.first);
 				}

 				
 			}

 			if(f == 1){
 				if(max_wt[u] >= 1){
 					count += max_wt[u];
 				}
 			}

 			if(ch.size() == N) {
 				break;
 			}


 		}
 	}

 	if(st.size() == N) {
 		cout<<"cnt "<<count<<endl;
 	}
 	else{
 		cout<<"out "<<-1<<endl;
 	}
 	//cout<<"count "<<count<<endl;-

*/