


#include<bits/stdc++.h>
using namespace std;


void max_product(vector<int> &a) {

	int p_max = a[0];
	int p_min = a[0];

	int ans = a[0];

	int n = a.size();


	for(int i = 0; i < n; i++) {

		if(a[i] == 0) {

		}
		int curr_max = max(a[i]*p_max,max(p_min*a[i],a[i]));
		p_min = min(a[i]*p_max,min(p_min*a[i],a[i]));

		ans = max(curr_max,ans);
		p_max = curr_max;

	}

	cout<<"ans "<<ans<<endl;
}

int main() {
	int n; cin>>n;
	vector<int> a(n);
	for(auto &x:a) {
		cin>>x;
	}


	max_product(a);



}