
/*
Move all negative numbers to beginning 
and positive to end with constant extra space
*/



#include<bits/stdc++.h>
using namespace std;


void seprate(vector<int> &a ) {

	int p = 0;
	int curr = 0;

	int N = a.size();
	while(curr < N) {

		if(a[curr] < 0) {
			swap(a[curr],a[p]);
			p++;
		}
		curr++;
	}


}

int main() {
	int n; cin>>n;
	vector<int> a(n);
	for(auto &x:a)cin>>x;

	seprate(a);

	for(auto x:a){
		cout<<x<<" ";
	}
}