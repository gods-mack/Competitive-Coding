
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

	// separate all negative left side
	while(curr < N) {

		if(a[curr] < 0) {
			swap(a[curr],a[p]);
			p++;
		}
		curr++;
	}

	for(auto x:a){
		cout<<x<<" ";
	}
	
	int plus  = p;
	
	// make alternate
	for(int i = 1; i < N and p < N; i+=2) {

		swap(a[p],a[i]);
		p++;
	}

	for(auto x:a){
		cout<<x<<" ";
	}



}

int main() {
	int n; cin>>n;
	vector<int> a(n);
	for(auto &x:a)cin>>x;

	seprate(a);

	
}