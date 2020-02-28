
// D- pair

#include<bits/stdc++.h>

typedef long long int ll;

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int  n; cin>>n;
	ll k; cin>>k;
	ll a[n];
	// for(int i = 0; i < n; i++){ scanf("%d",&a[i]); }
	int ng = 0;
	int z = 0;
	int p = 0;


	for(auto &x : a) {
		cin >> x;
		if(x < 0){ ng++; }
		if(x == 0){ z++; }
		if(x > 0){ p++; }
	}
	cout<<ng<<" "<<z<<" "<<p<<endl;

	int total_pair = (n * (n -1)) / 2;
	int neg_pair =  p*ng;
	int pos_pair =  (ng * (ng-1)) / 2;

	pos_pair  = pos_pair +  ( (p * (p-1)) / 2 ); 

	int zero_pair = total_pair - (neg_pair + pos_pair);

	cout<<"neg_pair "<<neg_pair<<endl;
	cout<<"zero_pair "<<zero_pair<<endl;
	cout<<"pos_pair "<<pos_pair<<endl; 




}