

// merge two sorted array in constant space

#include<bits/stdc++.h>
using namespace std;


void merge_array(vector<int>&a,vector<int>&b) {
	int m = a.size();
	int n = b.size();

	for(int i = 0; i < m; i++) {

		if(a[i] > b[0]){

			int j = 1; 
			int va	l = b[0];
			while(j < n){
				if(b[j] < a[i]) {
					b[j-1] = b[j];
				}
				else{
					break;
				}
				j++;
			}
			b[j-1] = a[i];
			a[i] = val;
		}
		cout<<"inter...\n";
		for(auto x:a) {
			cout<<x<<" " ;	
		}
		for(auto x:b) {
			cout<<x<<" ";
		}	
	
	}
}

int main()  {

	int m; cin>>m;
	vector<int> a(m);
	for(auto &x:a) cin>>x;

	int n; cin>>n;
	vector<int> b(n);
	for(auto &x:b) cin>>x;


	merge_array(a,b);	



	cout<<"###\n";
	for(auto x:a) {
		cout<<x<<" " ;	
	}
	for(auto x:b) {
		cout<<x<<" ";
	}	
}