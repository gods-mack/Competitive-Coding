
// Find First and Last Position of Element in Sorted Array
#include<bits/stdc++.h>
using namespace std;

int first_pos(vector<int>&a,int x){
	int low = 0;
	int high = a.size() - 1;
	int first_pos = a.size();

	while(low <= high){
		int mid = (low+high) / 2;
		if(a[mid] >= x){
			first_pos = mid;
			high = mid - 1;
		}
		else{
			low = mid + 1;
		}
	}

	return first_pos;
}

void searchRange(vector<int> &a, int x){


	int fp = first_pos(a,x);
	int sp = first_pos(a,x+1); // second pos
	

	if(fp <= sp){
		cout<<fp<<" "<<sp;
	}
	else{
		cout<<-1<<" "<<-1;
	}
}


int main(){
	int n; cin>>n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	int x; cin>>x;


	searchRange(a,x);
	
}