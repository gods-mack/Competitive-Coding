
#include<bits/stdc++.h>
using namespace std;

int demo(vector<int> V,vector<int>&W,int m,int sum,int cost) {


	if(sum < 0) {
		return 0;
	}
	if(m == 0 and sum >= 0) {
		return cost;
	}



	return max(demo(V,W,m-1,sum,cost), demo(V,W,m-1,sum-W[m],cost+V[m]));
}

int main() {
	int n; cin>>n;
	vector<int> V(n);
	vector<int> W(n);
	for(int i = 0; i < n; i++) {
		cin>>V[i];
	}
	for(int i = 0; i < n; i++) {
		cin>>W[i];
	}

	int sum; cin>>sum;

	cout<<"ans "<<demo(V,W,n,sum,0)<<endl;
}