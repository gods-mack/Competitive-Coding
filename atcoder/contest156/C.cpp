/*
Problem Statement

There are N

people living on a number line.

The i
-th person lives at coordinate Xi

.

You are going to hold a meeting that all N

people have to attend.

The meeting can be held at any integer coordinate. If you choose to hold the meeting at coordinate P
, the i-th person will spend (Xi−P)2

points of stamina to attend the meeting.

Find the minimum total points of stamina the N
people have to spend.

*/
#include<bits/stdc++.h>
using namespace std;

int getavg(vector<int> a, int total){

}

int main(){
	int n; cin>>n;
	vector<int> a(n);
	int ans = INT_MAX;

	for(int i=0;i<n;i++){cin>>a[i];}

	for(int i = 1; i <= 100; i++){

		int cost =0;
		for(int j = 0; j < n; j++){
			cost += pow(a[j]-i,2);
		}
		ans = min(ans,cost);
	}
	cout<<ans;
}