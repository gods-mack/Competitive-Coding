/*

Given an array arr[] of N integers, 
the task is to find the count of all the subsequences of
 the array that have positive product.

Example:

    Input: arr[] = {2, -3, -1}
    Output: 3
    {2}, {-3, -1} and {2, -3, -1} are the only possible 
    subsequences.


	*/


#include<bits/stdc++.h>
using namespace std;

int main(){
	int n; cin>>n;
	vector<int> a(n);

	int pos = 0; // no. of +ve element
	int neg = 0; // no. of -ve element
	for(int i = 0; i < n; i++){
		cin>>a[i];
		if(a[i] < 0){ 
			neg++;
		}
		else{
			pos++;
		}
	}

	int res = pow(2, pos);
	if(neg > 0){
		res = res * pow(2,neg-1);
	}

	res = res - 1; // for empty subseqnece

	cout<<res;

}