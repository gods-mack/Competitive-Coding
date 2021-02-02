

#include<bits/stdc++.h>
using namespace std;


void max_water(vector<int> &a) {

	int n = a.size();

	int res = 0;
	int l = 0;
	int r = n-1;

	while(r > l) {
		int x_min = min(a[l], a[r]);
		int width = r - l - 1;
		res = max(res, x_min*width);

		if(a[r] > a[l]) {
			l++;
		}
		else if(a[r] < a[l]){
			r--;
		}
		else{
			l++; r--;
		}
	}

	cout<<"max water: "<<res<<endl;
}

int main() {
	int n; cin>>n;
	vector<int> a(n);

	for(auto &x:a){
		cin>>x;
	}
	max_water(a);


}