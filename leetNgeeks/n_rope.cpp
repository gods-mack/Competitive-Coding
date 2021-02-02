

// https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1
#include<bits/stdc++.h>
using namespace std;

void min_cost(vector<int> &a){
	int n = a.size();

	priority_queue<int, vector<int>, greater<int>> pq;

	for(auto x:a){
		pq.push(x);
	}

	int cost = 0;

	while(pq.size() > 1) {

		int top1 = pq.top();
		pq.pop();
		int top2 = pq.top();
		pq.pop();

		pq.push(top1 + top2);
		cost += top1+top2;
	}

	cout<<"min cost: "<<cost<<endl;

}

int main() {

	int n; cin>>n;
	vector<int> a(n);
	for(auto &x:a) cin>>x;

	min_cost(a);	
}