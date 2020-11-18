
#include<bits/stdc++.h>
using namespace std;


void sol(int a[],int n){

	int l = 0;
	int r = n-1;

	int lsum = 0;
	int rsum = 0;
	while(l<=r){


		if(lsum == rsum){
			if(lsum == 0) {
				lsum += a[l++];
			}
			
		}
		else if(lsum > rsum ){
			rsum += a[r--];
		}
		else if(lsum < rsum){
			lsum += a[l++];
		}
	}
}


int main() {

	int n; cin>>n;
	int a[n];
	for(int i = 0; i < n; i++) {
		cin>>a[i];
	}

	sol(a,n);
}