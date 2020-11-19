
// Sort by Set Bit Count 
// https://practice.geeksforgeeks.org/problems/sort-by-set-bit-count1153/1

#include<bits/stdc++.h>
using namespace std;


bool cmp (int n1,int n2 ){

	return __builtin_popcount(n1) > __builtin_popcount(n2);

}

int main() {
	int n; cin>>n;
	vector<int> a(n);

	for(auto &x:a){
		cin>>x;
	}

	stable_sort(a.begin(),a.end(),cmp);

	for(auto x:a) {
		cout<<x<< " ";
	}
}