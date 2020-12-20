

#include<bits/stdc++.h>
using namespace std;

int main() {
	int n; cin>>n;
	vector<int> a(2*n+2);
	for(int i = 0; i < 2*n+2; i++) {
		cin>>a[i];
	}

	int x = 0;

	for(auto i:a){
		x = x ^ i;
		cout<<"X "<<x<<endl;
		if(x > 0) {
			//cout<<"# "<<i<<endl;
			//x = 0;
		}
	}
	cout<<x<<endl;

}