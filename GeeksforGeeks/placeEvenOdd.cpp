

// Even numbers at even index and
//  odd numbers at odd index

#include<bits/stdc++.h>
using namespace std;


void sol(vector<int> &a,int n) {


	int even = 0;  // even index
	int odd  = 1;  // odd index

	int i = 0;

	while(1) {
		while(even < n && a[even]%2==0){
			even +=2;
		}
		while(odd < n && a[odd]%2 != 0){
			odd += 2;
		}

		if(even < n && odd < n) {  // found irregularity
			swap(a[even],a[odd]);
		}
		else{  // everthig is fine already
			break;
		}
	}


}


int main() { 
	int n; cin>>n;
	vector<int> a(n+1);
	for(int i = 0; i < n; i++) {
		cin>>a[i];
	}

	sol(a,n);
	cout<<"After "<<endl;
	for(int i = 0; i < n; i++) {
		cout<<a[i]<<" " ;
	}
}