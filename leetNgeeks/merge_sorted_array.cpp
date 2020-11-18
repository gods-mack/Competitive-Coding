

#include<bits/stdc++.h>
using namespace std;


void merge(vector<int> &a,vector<int>&b) {

	int r_a = a.size()-1;
	int r_b = b.size()-1;

	while(r_b >= 0) {

		if(a[r_a] > b[r_b]) {
			swap(a[r_a],b[r_b]);
			r_b--;
		}
		else{
			r_b--;
		}

	}

	int val = a[r_a];
	
	while(val < a[r_a-1]) {
		a[r_a] = a[r_a-1];
		r_a--;
	}
	a[r_a] = val;

}

int main() {
	int n1; cin>>n1;
	vector<int> a(n1);
	for (int i = 0; i < n1; ++i)
	{
		cin>>a[i];
	}
	int n2; cin>>n2;
	vector<int> b(n2);
	for (int i = 0; i < n2; ++i)
	{
		cin>>b[i];
	}

	merge(a,b);
	for(auto x:a){
		cout<<x<<" ";
	}
	cout<<"\n";
	for(auto x:b) {
		cout<<x<<" ";
	}
}