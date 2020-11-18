

#include<bits/stdc++.h>
using namespace std;



// median of two sorted array

void median(vector<int> &a, vector<int> &b) {

	int m = a.size();
	int n = b.size();

	int total_size = m + n;
	int mid_count = 0;

	int ans ;
	int i = 0;
	int j = 0;
	

	int el1 ;
	int el2 ;

	for(int k = 0; k <= (total_size)/2; k++) {


		if(i == m) {
			el1 = el2;
			el2 = b[0];
			break;
		}
		else if(j == n) {
			el1 = el2;
			el2 = a[0];
			break;
		}

		if(a[i] <= a[j]) {
			el1 = el2;
			el2 = a[i];
			i++;
		}
		else{
			el1 = el2;
			el2 = b[j];
			j++;
		}

	}


	cout<<"median  "<<(el1+el2)/2;



}

int main() {
	int m; cin>>m;
	vector<int> a(m);
	for(auto &x: a) cin>>x;

	int n; cin>>n;
	vector<int> b(n);
	for(auto &x:b) cin>>x;

	median(a,b);	


}