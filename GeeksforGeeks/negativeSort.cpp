

// Rearrange positive and negative numbers

#include<bits/stdc++.h>

using namespace std;


void merge(vector<int> &a,int l,int m,int r) {

	int n1 = m - l + 1;
	int n2 = r-m;
	int L[n1];
	int R[n2];


	for(int i = 0; i < n1; i++) {
		L[i] = a[l+i];
	}
	for(int j = 0; j < n2; j++) {
		R[j] = a[m+1+j];
	}

	int k = l;	
	int i,j; i = j = 0;
	while(i < n1 and L[i]<0) {
		a[k++] = L[i++];
	}
	while(j < n2 and R[j] < 0) {
		a[k++] = R[j++];
	}

	while(i < n1) {
		a[k++] = L[i++];
	}
	while(j < n2) {
		a[k++] = R[j++];
	}

}


void mergeSort(vector<int> &a, int l , int r) {

	if(l < r) {
		int mid =(l+r)/2;

		mergeSort(a,l,mid);
		mergeSort(a,mid+1,r);
		merge(a,l,mid,r);
	}
}

int main() {
	int n; cin>>n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin>>a[i];
	}

	mergeSort(a,0,n-1);
	cout<<"After extarction\n";
	for(int i = 0; i < n; i++) {
		cout<<a[i]<<" ";
	}


}