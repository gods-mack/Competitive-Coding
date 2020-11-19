

// Print all subarrays with 0 sum

//https://www.geeksforgeeks.org/print-all-subarrays-with-0-sum/


#include<bits/stdc++.h>
using namespace std;


void sol(vector<int> &a,int n) {

	unordered_map<int,vector<int> > mp;


	int sum = 0;
	int count = 0;
	for(int i = 0; i < n; i++) {
		sum += a[i];
		//cout<<"sum "<<sum<<endl;

		if(sum == 0) {
			cout<<0<<" "<<i<<endl;
		}
		if(mp.find(sum)!=mp.end()) {

			vector<int> v = mp[sum];
			for(auto x:v) {
				cout<<x+1<<" "<<i<<endl;
			}
		}
		
		

		mp[sum].push_back(i);
	}

	//cout<<"count "<<count<<endl;
}

int main() {

	int n; cin>>n;
	vector<int> a(n);
	for(auto &x:a)
		cin>>x;

	sol(a,n);	

		
}