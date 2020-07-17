

#include<bits/stdc++.h>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t; 
	while(t--) {
		int n; cin>>n;
		long int x; cin>>x;

		vector<long int> a(n);
		for(int i = 0; i < n; i++) {
			cin>>a[i];
		}
		sort(a.begin(),a.end());

		int cost = 0;

		for(int i = 0; i < n; i++) {
			while(x < a[i]) {
				x = x*2;
				cost++;
			}
			if(a[i] == x) {
				cost++;
				x=x*2;
				a[i] = 0;
			}
			else if(2*a[i] >= x) {
				x=2*a[i];
				cost++;
				a[i] = 0;
			}
		}
		for(int i = 0; i < n; i++) {
			if(a[i] != 0) {
				cost++;
			}
		}
		cout<<cost<<endl;
		


	}
}