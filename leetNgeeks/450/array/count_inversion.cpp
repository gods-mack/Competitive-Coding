

#include<bits/stdc++.h>
using namespace std;



// efficient sol
int total = 0;

int  merge(vector<int> &a,int l,int mid,int r) {

	int inversions = 0;

	int n1 = mid-l+1;
	int n2 = r-mid;
	int L[n1];
	int R[n2];

	for(int i=0;i<(n1);i++) {
		L[i] = a[l+i];
	}
	for(int i=0;i<(n2);i++) {
		R[i] = a[mid+1+i];
	}

	int i = 0;
	int j = 0;
	int k = l;
	while(i < n1 && j < n2) {

		if(L[i] <= R[j]) {
			a[k] = L[i];
			k++; i++;
		}
		else {
			cout<<"n1 i"<<n1<<" "<<i<<endl;
			inversions += (n1-i);
			a[k] = R[j];
			k++; j++;
		}
	}

	while( i < n1) {
		a[k++] = L[i++];
	}
	while( j < n2) {
		a[k++] = R[j++];
	}

	return inversions;


}
int merge_sort(vector<int> &a,int l,int r){


	int total_inversions = 0;

	if(l < r) {
		int mid = (l+r)/2;
		total_inversions =  merge_sort(a,l,mid);
		total_inversions += merge_sort(a,mid+1,r);
		total_inversions +=  merge(a,l,mid,r);
	}

	return total_inversions;
}

void count_inver(vector<int> &a) {


}


// brute-force solution
void count_(vector<int> a) {

	int count = 0;

	int n = a.size();
	for(int i = 0; i < n-1; i++) {

		for(int j = 0; j < n-1; j++) {
			if(a[j] > a[j+1]){
				swap(a[j],a[j+1]);
				count++;
			}
		}
	}

	cout<<"count "<<count<<endl;
	for(auto x:a) {
		cout<<x<<" ";
	}
}

int main() {
	int n; cin>>n;
	vector<int> a(n);
	for(auto &x:a) cin>>x;

	count_(a);
	cout<<"inv "<<merge_sort(a,0,a.size()-1)<<endl;
	//cout<<"\n total "<<total<<endl;
	for(auto x:a) {
		cout<<x<<" ";
	}
}