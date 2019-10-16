/*
Given a permutation of first n natural numbers as an array and an integer k. 
Print the lexicographically largest permutation after at most k swaps.
*/


#include<bits/stdc++.h>
using namespace std;

void largestPermut(vector<int> a, int n, int k){
	vector<int> tmpArray(n+1);

	for(int i = 0 ;i  < n; i++){
		tmpArray[a[i]] = i;
	}


	for(int  i = 0 ; i < n ; i++){

		if(a[i] == n-i){
			continue;
		}

		int tmp  = tmpArray[n-i];  // find index of largest element

		tmpArray[a[i]] = tmpArray[n-i];
		tmpArray[n-i] = i;

		swap(a[tmp], a[i]);

		--k;
		if(k==0){
			break;
		}
	}


// final answer
	for(int i = 0 ; i < n; i++){
		cout<<a[i]<<" ";
	}
}

int main(){
	
		int n;
		cin>>n;
		int k;
		cin>>k;
		vector<int>  a(n);
		for(int i = 0; i < n; i++){
			cin>>a[i];
		}
		
		largestPermut(a,n,k);

}