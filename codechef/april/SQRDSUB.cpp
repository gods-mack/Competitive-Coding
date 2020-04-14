

// question: 4

#include<bits/stdc++.h>
//typedef long long int ll;
//#define int long long
using namespace std;

#define int long long 

bool isValid(int n){

	if(n%2 != 0 || n%4 == 0){
		return true;
	}

	return false;
}

signed main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin>>t;
	while(t--){
		int n; cin>>n;

		vector<int> a(n);
		for(int i = 0; i < n; i++){
			cin>>a[i];
			a[i] = abs(a[i]);
		}
		vector<int> b(n);
		
		
		for(int i = 0; i < n; i++){
			if(a[i]%4 == 0) { b[i] = 2; }
			else if(a[i]%2 == 0) { b[i] = 1; }
			else { b[i] = 0; }
		}
		
		
		int count = 0;
		
		int curr_sum = 0;
		map<int,int> mp;
		for(int i = 0; i < n; i++){
			curr_sum += b[i];
			if(curr_sum == 1){
				count++;
			}
			
			if(mp.find(curr_sum - 1) != mp.end()){
				count += mp[curr_sum -1 ];
			}
			
			mp[curr_sum ]++;
		}
			
			
		//cout<<a"ans "<<ans-count;	
		cout << ((n*(n+1))/2 - count) << endl;

		

	}
	return 0;

}
