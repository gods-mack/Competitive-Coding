/*
Write a method which accepts 2 Integer Arrays and their
 size N . Element B[j] for j=0..N should be equal t
 o product of all the elements A[i] i=0..n such that
  i!=j .Eg : A : {2,5,4,10} B should be {200,80,100,40 }
Time Complexity O(N)
*/

// https://practice.geeksforgeeks.org/problems/product-array-puzzle4525/1

#include<bits/stdc++.h>
using namespace std;


void sol(vector<int> &a,int n) {

	int zeros = 0;

	vector<int> b(n,0);// answer array

	int all_product = 1;
	for(int i = 0; i < n; i++) {
		if(a[i] == 0) {
			zeros++;
			continue;
		}
		all_product = all_product * a[i];
	}

	if(zeros  >=1) {
		if(zeros == 1) {
			for(int i = 0; i < n; i++) {
				if(a[i] == 0) {
					b[i] = all_product;
				}
			}
		}
		else{
			// b array will alwyas will be zero
		}

		for(auto x:b) {
			cout<<x<<" ";
		}
		return;
	}
	



	for(int i = 0; i < n; i++) {
		b[i] = all_product/a[i];
		cout<<b[i]<<" ";
	}




}
int main() {
	int n;cin>>n;
	vector<int> a(n);
	for(auto &x:a) {
		cin>>x;
	}

	sol(a,n);
	



}
