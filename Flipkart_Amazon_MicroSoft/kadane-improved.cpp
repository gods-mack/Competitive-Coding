// Given an array arr of N integers. Find the contiguous sub-array with maximum sum.    
    
    

#include<bits/stdc++.h>
using namespace std;

int  kadane_algo(vector<int> a){
	int n = a.size();
	int curr_max = a[0];
	int max_so_far = a[0];
	
	for(int i = 1; i < n; i++){
		curr_max = max(a[i],curr_max + a[i]);
		max_so_far = max(max_so_far, curr_max);
	}
	if(curr_max == 0){
		return -1;
	}
	else{
		return max_so_far;
	}
}

int main(){
    int T; cin>>T;
    while(T--){
	int n;
	 cin>>n;
	 vector<int> a(n);
	 for(int i = 0; i <n; i++){
	 	cin>>a[i];
	 }
	 cout<<kadane_algo(a)<<endl;
    }
}
