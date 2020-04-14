

// question: 2

#include<bits/stdc++.h>
typedef long long int ll;
#define MOD 1000000007
using namespace std;




int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin>>t;

	while(t--){
		ll n; cin>>n;
		vector<ll> a(n);
		
		for(ll i = 0; i < n; i++){
			cin>>a[i];
		}	

		int time = 0;
		ll ans = 0;
		ll i = 0;

		sort(a.begin(),a.end(),greater<int>());

		while(i < n){
			if(a[i]-time > 0){
				ans  = ans +  a[i]-time;
				time++;
				
			}
			i++;
		}

		
		cout<< ans % MOD << endl;
	}
}