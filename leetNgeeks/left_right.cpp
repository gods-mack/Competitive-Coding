
#include<bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;

	while(t--) {

		int n; cin>>n;
		vector<int> a(n);
		vector<int> mx_a(n);
		vector<int> mn_a(n);
		int mx = INT_MIN;
		int mn = INT_MAX;

		int impo = 0; // impossible flag
		for(int i = 0; i < n; i++) {
			cin>>a[i];
			mx = max(mx,a[i]);
			mx_a[i] = mx;
		}
		for(int i = n-1; i>=0; i--) {
			mn = min(mn,a[i]);
			mn_a[i] = mn;
		}


		for(int i = 0; i < n; i++) {
			if(mn_a[i] == mx_a[i] and i!=0 and i!=n-1){
			//	cout<<"found "<<a[i]<<endl;
				cout<<a[i]<<endl;
				impo = 1;
				break;

			}
		}
		if(!impo) {
			cout<<-1<<endl;
		}

	}
}