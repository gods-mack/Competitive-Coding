


#include<bits/stdc++.h>
using namespace std;


void insert_in() {
	
}

int main() {
	int n; cin>>n;
	vector<vector<int>> intervals;
	for(int i = 0; i < n; i++) {
		//intervals[i].resize(2);
		vector<int> tmp(2);
		int a; cin>>a; int b; cin>>b;
		tmp[0] = a;
		tmp[1] = b;
		intervals.push_back(tmp);
	}


	vector<int> new_interval;
	for(int i = 0; i <2; i++) {
		int x; int y;cin>>x>>y;
		new_interval.push_back(x);
		new_interval.push_back(y);
	}


}