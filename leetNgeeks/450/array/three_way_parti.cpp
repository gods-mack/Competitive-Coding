	
#include<bits/stdc++.h>
using namespace std;


void partitioning(vector<int> &a,int x,int y) {

	sort(a.begin(),a.end());
} 

int main() {
	int n;
	cin>>n;
	vector<int> a(n);
	for(auto &x:a) cin>>x;

	int x; cin>>x;
	int y; cin>>y;
	partitioning(a,x,y);	
}