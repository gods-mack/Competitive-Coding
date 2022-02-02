

// Medium


#include<bits/stdc++.h>
using namespace std;


void max_prod(vector<int> a){

	int local_product = 1;
	int max_prod = INT_MIN;

	for(int i = 0; i < N; i++) {
		local_product *= a[i];

		if(local_product  > max_prod) {
			max_prod = local_product;
		}

		if(local_product < 0) {
			local_product = 1;
		}
	}

	
}


int main(){
	int n; cin>>n;
	vector<int> a(n);
	for(auto &x: a) {
		cin>>x;
	}
}

