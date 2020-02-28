// C- Poll

/*
We have N voting papers. The 
i-th vote (1≤i≤N) has the string Si

written on it.

Print all strings that are written on t
he most number of votes, in lexicographical order.

*/

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n; cin>>n;
	map<string,int> hash;
	int maXX = INT_MIN;

	for(int i = 0; i < n; i++){
		string s; cin>>s;
		hash[s]++;
		if(hash[s] > maXX){
			maXX = hash[s];
		}
	}
	cout<<maXX<<endl;

	for(auto it = hash.begin(); it!=hash.end(); ++it){
		if((int)it->second == maXX)
			cout<<it->first<<" "<<it->second<<endl;
	}
}