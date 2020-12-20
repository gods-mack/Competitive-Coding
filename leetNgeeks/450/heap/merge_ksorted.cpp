
//  Merge k Sorted Arrays 

#include<bits/stdc++.h>
using namespace std;



struct compare  
 {  
   bool operator()( pair<int,pair<int,int>> h1, pair<int,pair<int,int>> h2)  
   {  
       if(h1.first > h2.first){
       	return true;
       } 
       return false;
       //int ans = h1.first - h2.firs
   }  
 };



void merge_k(vector<vector<int>> a,int k) {


	priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>> >,
						compare > pq;

	for(int i = 0; i < k; i++) {
		pq.push({a[i][0],{i,0}});
	}

	vector<int> ans;

	while(!pq.empty()) {

		auto curr = pq.top();
		pq.pop();

		ans.push_back(curr.first);

		int x = curr.second.first;
		int y = curr.second.second;

		if(a[x].size()  == y+1) {
			continue;
		}

		pq.push({a[x][y+1],{x,y+1}});
	}					



	cout<<"answer\n";
	for(auto x:ans) {
		cout<<x<<" ";
	}




}


int main() {
	int k; cin>>k;

	int n; cin>>n;

	vector<vector<int>> a(k);

	for(int i = 0; i < k; i++) {

		//int n; cin>>n;
		a[i].resize(n);

		for(int j = 0; j < n; j++) {
			cin>>a[i][j];
		}
	}


	merge_k(a,k);


}