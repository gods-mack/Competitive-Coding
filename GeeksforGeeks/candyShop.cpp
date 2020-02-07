/*
In a candy store there are N different types of candies 
available  
and the prices of all the N different types of
 candies are provided to you.
You are now provided with an attractive offer.
You can buy a single candy from the store and get
 atmost K other candies ( all are different types ) for free.
Now you have to answer two questions. Firstly, 
you have to tell what is the minimum amount of money 
you have to spend to buy all the N different candies. Secondly,
you have to tell what is the maximum amount of money you have 
to spend to buy all the N different candies.
In both the cases you must utilize the offer i.e. 
you buy one candy and get K other candies for free.

Example:
Input    
 1
 4  2
 3 2 1 4

Output
 3 7

*/

#include<bits/stdc++.h>
using namespace std;

void sol(vector<int> &a, int k){

	int n = (int)a.size();
	sort(a.begin(),a.end());

	int min_cost = 0;
	int max_cost = 0;
	int tmp = n;
	int i = 0;
	
	for(int i = 0; i < n; i++){
		min_cost += a[i];
		n = n - k;
	}
	n = tmp;
	int limit = 0;
	for(int i = n-1; i>=limit; i--){
		max_cost += a[i];
		limit += k;
	}
	cout<<min_cost<<" "<<max_cost<<endl;
}

int main(){
	int n; cin>>n;
	int k; cin>>k;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}

	sol(a,k);


}