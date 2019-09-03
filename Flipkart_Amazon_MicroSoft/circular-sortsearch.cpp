


/*
Given a sorted and rotated array A of N distinct elements which is rotated at some point, 
and given an element K. The task is to find the index of the given element K in the array A.
*/


#include<bits/stdc++.h>
using namespace std;


int findNumber(vector<int> a, int  low, int high, int x){

	while(high >= low){
		int mid = (low+high)/2;

		if(a[mid] == x){
			cout<<"we got index :";
			return mid;
		}
		if(a[high] >= a[mid]){ // right is sorted
			if(x > a[mid] and x <= a[high]){
				//findNumber(a,mid+1,high,x);
				low = mid+1;
			}
			else{
				//findNumber(a,low,mid-1,x);
				high = mid - 1;
			}
		}
		if(a[low] <= a[mid] ){
			if(x >= a[low] and x < a[mid]){
				//findNumber(a,low,mid-1,x);
				high =  mid-1;
			}
			else{
				//findNumber(a,mid+1,high,x);
				low = mid + 1;
			}
		}
	}
}

int main(){

	int n;
	cin>>n;
	std::vector<int> a(n);
	for(int i = 0; i < n ; i++){
		cin>>a[i];
	}
	int ser;
	cin >>ser;
	cout<<findNumber(a,0,n-1,ser)<<endl;
}
