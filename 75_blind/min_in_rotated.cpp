

#include<bits/stdc++.h>
using namespace std;


int find_pivot(vector<int> a, int l , int r){

	//if(a[r] > a[l]){ return 0;}
	if(l == r){ cout<<" find " << a[l]; return a[l];}

	int mid = (l+r)/2;

	if(a[mid] > a[mid+1]){
		cout<<"pivot " << a[mid]<<endl;
		return mid;
	}

	if(a[mid] > a[l]){
		return find_pivot(a, mid+1, r);
	}
	else{
		return find_pivot(a, l, mid-1);
	}

}

void find_min(vector<int> a){

	int pivot = find_pivot(a,0 , a.size()-1 );
}

int main() {
	int n; cin>>n;
	vector<int> a(n);

	for(int i=0; i<n; i++) {
		cin>>a[i];
	}


	find_min(a);
}