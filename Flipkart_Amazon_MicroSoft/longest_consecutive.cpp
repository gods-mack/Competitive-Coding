/*
URL : https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence/0

Given an array arr[] of positive integers. Find the length of the longest sub-sequence s
uch that elements in the subsequence 
are consecutive integers, the consecutive numbers can be in any order.

*/


#include<bits/stdc++.h>
using namespace std;

int longest_consecutive(std::vector<int> a){
	sort(a.begin(), a.end());
	int count  = 1;
	int max_count = 1;

	for(int i = 1; i < (int)a.size() ; i++){
		if(a[i] == a[i-1]+1){
  			count++;
  			if(max_count < count){
			    max_count = count;
		    }
		}
		else{
			count = 1;
		}

	}

	return max_count;

}

int main(){
	int T; cin>>T;
	while(T--){
		int n;
		cin>>n;
		std::vector<int> a(n);
		for(int i = 0; i < n; i++){
			cin>>a[i];
		}
		cout<<longest_consecutive(a)<<Endl;
	}
}
