

#include<bits/stdc++.h>
#define MAX 200000

using namespace std;

struct node{
	int p;
	map<char,int> hh;
};


int main(){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while(t--){

	 int n; int m; 
	 cin>>n>>m;
	 struct node arr[n];

	 char s[MAX];
	 for(int i = 0; i < n; i++){
	 	char c; cin>>c;
	 	s[i] = c;
	
	 }	
	


	 map<char,int> hash;
	 map<char,int> ans;

	// cout<<"yha0\n";
	 for(int i = 0; i < 26; i++){
	 	char c = i + 97;
	 	ans[c] = 0;
	 }


	 for(int i = 0; i < n; i++) {
	 	arr[i].p = i;
	 	hash[s[i]]++;
	 	arr[i].hh.insert(hash.begin(),hash.end());

	 }

	 for(int i = 0; i < m; i++){
	 	int x; cin>>x;
	 	map<char,int> tmp = arr[x-1].hh;
	 	for(auto it=tmp.begin();it!=tmp.end();++it){
	 		ans[it->first] += it->second;
	 	}

	 	if(i==m-1){ // for complete string
	 		map<char,int> tmp1 = arr[n-1].hh;
	 		for(auto it=tmp1.begin();it!=tmp1.end();++it){
	 			ans[it->first] += it->second;
	 		}
	 	}
	 	
	 }


	 //for(int i = 0; i < n; i++){ hash[s[i]]++; }
	 
	  for(int i = 0; i < 26; i++){
	 	char c = i + 97;
	 	cout<<ans[c]<<" ";
	 	
	  }
	  cout<<endl;

	}
	 
}

/*
for(auto it = arr[x].h.begin(); it!=arr[x].h.end();++it){
	 		ans[it->first] += it->second;
	 	}

*/
