/*
Given an array of positive integers of size N, 
form groups of two or three such that the sum of
 all elements in a group is a multiple of 3. Count 
 all possible number of groups that can be generated 
 in this way



// https://practice.geeksforgeeks.org/problems/possible-groups/0
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

	int n; cin>>n;
	vector<int> a(n);
	map<int,int> hs;
	int maxx = -1;

	for(auto &x:a){
		cin>>x;
		if(maxx < x) {
			maxx = x;
		}
		hs[x]++;
	}

	int count = 0;
	cout<<"maxx "<<maxx<<endl;
	// two number groups
	for(int i = 0; i < n; i++) {

		for(int j = 1; j<=maxx; j++) {
			if(j == a[i]){
				continue;
			}
			if((a[i]+j)%3 == 0 and hs.find(j)!=hs.end()){

				count++;

				for(int k = 3; k <= maxx; k+=3) {
					if(a[i]+j+k % 3 ==0 and hs.find(k)!=hs.end()){
						count++;
					}
				}
			}
		}
	}


	//cout<<"count "<<count<<endl;
	cout<<count<<endl;

	

}