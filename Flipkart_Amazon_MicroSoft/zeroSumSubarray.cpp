
/*
You are given an array A of size N. You need to print the total 
count of sub-arrays having their sum equal to 0

Time Should be O(N) , N=input size 
*/


#include<bits/stdc++.h>
using namespace std;

int getSubarray(vector<int> a){
	int n = a.size();	
	unordered_map<int,int> hash;

	
	cout<<endl;
	for(auto it = hash.begin(); it != hash.end(); ++it){
		cout<<it->first<<" "<<it->second<<endl;
	}

	int count  = 0;
	int sum  = 0;
	for(int i = 0; i < n; i++){
		sum += a[i];
		if(hash.find(sum) != hash.end()){
			count  = count + hash[sum];
		}
		hash[sum]++;
	}

	return count;
}

int main(){
	int T; cin>>T;
	while(T--){
		int n; cin>>n;
		vector<int> a(n);
		for(int i = 0; i < n; i++){
			cin>>a[i];
		}

		cout<<getSubarray(a)<<endl;
	}
}
