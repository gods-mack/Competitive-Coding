
/*
URL : https://www.geeksforgeeks.org/minimum-operations-required-to-make-every-element-greater-than-or-equal-to-k/

Minimum operations required to make every element greater than or equal to K

Given an array of length N. The task is to convert it into a sequence
in which all elements are greater than or equal to K.The only operation allowed is taking two
smallest elements of the sequence and replace them by their LCM. Find the minimum number of operations required.
If it is impossible to get such an array, print -1.

*/



#include <bits/stdc++.h>
using namespace std;

int LCM(int a,int b){
	int lcm ;
	if(a>b){
		lcm = a;
	}
	else{
		lcm = b;
	}
	while(1){
		if(lcm%a==0 and lcm%b==0){
			return lcm;
		}
		lcm++;
	}
	
}
	
int  maximize(vector<int> &a, int k){
	int size = a.size();
	priority_queue<int, vector<int> ,greater<int> > pq;
	for(auto x: a){
		pq.push(x);
	}
	
	int count = 0;
	while(1){
		
		
		if(pq.top() >= k){
			break;
		}
		
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
			
		pq.push(LCM(a,b));
		count++;
	
		
		if(pq.size() < 2){   // impossible condition
			return -1;
		}
	}
		
	
	return count;

	
}

int main(){
	int n; int k;
	cin>>n>>k;
	vector<int> a(n);
	for(int i = 0; i<n; i++){
		cin>>a[i];
	}
	
	cout<<maximize(a,k);
}
