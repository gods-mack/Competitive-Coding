

// https://leetcode.com/problems/partition-array-for-maximum-sum/


#include<bits/stdc++.h>
using namespace std;


int global = 0;

int range_sum(int l, int r,vector<int> &a) {

	int maxx = INT_MIN;
	for(int i = l; i <= r and i  < a.size(); i++) {
		maxx = max(maxx,a[i]);
	}

	return maxx*(r-l + 1);
}

int demo(int &ind,vector<int>&a,int &sum,int k ){

	int N = a.size();
	if(ind >= N) {
		return 0;
	}

	int tmp = INT_MIN;
	for(int i = ind; i < ind+k; i++) {

		int res = range_sum(ind,i,a) + demo(i,a,sum,k);
		tmp = max(tmp,res);
	} 
	global = max(tmp,global);

	return  global;
}

int main() {
	int n; cin>>n;
	vector<int> a(n);
	for(auto &x:a) cin>>x;

	int k; cin>>k;

	int sum = 0;
	int ind = 0;
	cout<<"ans "<<demo(ind,a,sum,k)<<endl;


}