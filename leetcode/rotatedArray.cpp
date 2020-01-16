

#include<bits/stdc++.h>
using namespace std;


int findPivot(vector<int> a, int low,int high){
	if(low > high){
		return -1;
	}
	if(low == high){
		return low;
	}

	int mid = low + (high - low) /2;
	if(mid < high and a[mid] > a[mid+1]){
		return mid;
	}
	if(mid > low and a[mid] < a[mid]-1){
		return mid-1;
	}

	if(a[low] >= a[mid]){
			return findPivot(a,low,mid-1);
	}
	return findPivot(a,mid+1,high);
}

int binarySearch(vector<int> a, int l ,int r,int x){
	if(l > r){
		return -1;
	}
	
		int mid = (l+r)/2;

		if(a[mid] == x){
			return mid;
		}
		if(a[mid] > x){
			return binarySearch(a,l,mid-1,x);
		}
		if(a[mid] < x){
			return binarySearch(a,mid+1,r,x);
		}
	
}

int searchElement(vector<int> a, int n, int x){

	int pivtIndex = findPivot(a,0,n-1);
	cout<<"pivot "<<pivtIndex<<endl;

	if(pivtIndex == -1){
		return binarySearch(a,0,n-1,x);
	}

	if(a[pivtIndex] == x){
		return pivtIndex;
	}

	if(a[0] <= x){
		return binarySearch(a,0,pivtIndex-1,x);
	}
	return binarySearch(a,pivtIndex+1,n-1,x);

}


int main(){
	int n; cin>>n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	/*for(int i = 0; i < 3; i++){
		int element; cin>>element;
		bs(a,0,n-1,element);
		cout<<endl;
	}*/
	int x; cin>>x;
	cout<<"elemnt found at "<<searchElement(a,n,x);
	
}