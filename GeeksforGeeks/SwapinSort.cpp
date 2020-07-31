
#include<bits/stdc++.h>
using namespace std;


void sol(vector<int> a) {

	int n = a.size();

	pair<int,int> apair[n];

	for(int i = 0; i < n; i++) {
		apair[i].first = a[i];
		apair[i].second = i;
	}
	int count = 0;

	sort(apair,apair+n);

	vector<bool> visited(n,false);

	for(int i = 0; i < n; i++) {

		if( visited[i]==false or apair[i].second==i ){
			continue;
		}	

		int j = i;
		int cycle = 0;

		while(!visited[j]) {
			visited[j] = true;
			j = apair[j].second;
			cycle++;
		}

		if(cycle > 0) {
			count += (cycle-1);
		}
		
	}

	cout<<count;



}


int  main() {
	int n; cin>>n;

	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin>>a[i];
	}

	sol(a);

}