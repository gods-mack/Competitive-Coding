

/*




*/

#include<bits/stdc++.h>
using namespace std;



void heapify(vector<int>&a,int n,int ind) {

	//int n = a.size();
	if(ind >= n) {
		return;
	}

	int left = 2*ind + 1;
	int right = 2*ind + 2;

	int largest = ind;
	if(left < n && a[left] > a[largest]) {
		largest = left;
	}
	if(right < n && a[right] > a[largest]) {
		largest = right;
	}

	if(largest != ind) {
		swap(a[largest], a[ind]);

		heapify(a,n,ind);
	}
}

void k_largest(vector<int> &a,int k) {

	int n = a.size();

	// make max-heap
	for(int i = n/2-1; i >= 0; i--) {
		heapify(a,n,i);
	}

	// now extract larger element every time
	for(int i = n-1; i > 0; i--) {
		swap(a[i],a[0]);
		heapify(a,i,0);
	}

	for(auto x:a) {
		cout<<x<<" ";
	}


}

int main() {
	int n; cin>>n;
	vector<int>a(n);
	for(auto &x:a) {
		cin>>x;
	}

	int k; cin>>k;

	k_largest(a,k);
}