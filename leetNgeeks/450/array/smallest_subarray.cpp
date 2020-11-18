

//  Smallest subarray with sum greater than x 

// https://practice.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x/0#

#include<bits/stdc++.h>
using namespace std;





// brute-force O9n^2)
void sol(vector<int> a,int k) {

	int n = a.size();
	vector<int> tmp(n,0);

	int min_length = INT_MAX;

	for(int i = 0; i < n; i++) {

		int sum = 0;
		for(int j = i; j < n; j++) {
			sum += a[j];
			if(sum > k) {
				min_length = min(min_length,j-i+1);
				break;
			}

		}

	}

	cout<<"min_length "<<min_length<<endl;

}


// effiecient sol O(N)

void Smallest_sbarray(vector<int> a,int k) {

	int min_length = INT_MAX;
	int sum = 0;
	int start = 0;
	int n = a.size();

	for(int i = 0; i < n; i++) {

		sum += a[i];
		if(sum > k) {
			
			while(sum > k and start < n) {
				min_length = min(min_length,i-start); 
				sum -= a[start];
				start++;
			}
		}
	}

	cout<<"min_length "<<min_length<<endl;
}

int main() {
	int n; cin>>n;

	vector<int>a(n);
	for(auto &x:a)cin>>x;

	int k; cin>>k;
	sol(a,k);	
	Smallest_sbarray(a,k);
}