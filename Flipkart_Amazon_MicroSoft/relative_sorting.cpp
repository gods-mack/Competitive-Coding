

//  Relative Sorting 
/*
Given two arrays A1[] and A2[] of size N and M respectively.
 The task is to sort A1 in such a way that the relative order among the elements will be 
 same as those in A2. For the elements not present in A2, append them at last in sorted order. 
 It is also given that the number of elements in A2[] are smaller than or equal to number of elements 
 in A1[] and A2[] has all distinct elements.

Note: Expected time complexity is O(N log(N)).

*/



#include<bits/stdc++.h>
using namespace std;

map<int, int> has;

void relativeSorting(std::vector<int> &a, std::vector<int > &b){

	for(auto x : b){  // comapre hash with second array and ,print each number its frequence times.
		int count = has[x];
		for(int i = 0; i<count; i++){
			cout<<x<<" ";
		}
		has.erase(x);
	}
	//cout<<"remaing  elements "<<endl;
	for(auto it = has.begin(); it != has.end(); ++it){
		int count = it->second;
		for(int  i = 0; i<count; i++){
			cout<<it->first<<" ";
		}
		has.erase(it);
	}
}

int main(){
        int T; cin>>T;
	while(T--){
	
	int m,n;
	cin>>m>>n;
	std::vector<int> a(m);
	std::vector<int> b(n);
	for (int i = 0; i < m; ++i){
		cin>>a[i];
		has[ a[i] ]++;
	}
	
	for (int i = 0; i < n; ++i){
		cin>>b[i];
	}

	
	//cout<<"Function called"<<endl;     // debugging STDOUT

	relativeSorting(a,b);
	cout<<endl;
		
	} // end of testCase loop	
	
}  // main end
