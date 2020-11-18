

#include<bits/stdc++.h>
using namespace std;


void merge(vector<int> a, int l,int m,int r) {

	int L[m-l+1];
	int R[r-m];

	int n1 = (m-l+1);
	int n2 = (r-m);
	for(int i = 0; i < (m-l+1); i++){
		L[i] = a[l+i];
	}
	for(int j = 0; j < (r-m); j++) {
		R[j]  = a[j+m+1];
	}


	int i = 0;
	int j = 0;
	int k = l;
	while( i < n1 && j < n2){
		if(L[i] <= R[j]){

		}
		else{
			i
		}
	}


}


void mergeSort(vector<int> a, int l,int r) {

	if(l < r) {
		int mid = (l+r)/2;

		mergeSort(a,l,mid);
		mergeSort(a,mid+1,r);
		merge(a,l,m,r);
	}
}


int main() {
	int n; cin>>n;
	vector<int> a(n);
	for(auto &x:a){
		cin>>x;
	}


}