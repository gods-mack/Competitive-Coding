
// 0-1 knapsack top down

#include<bits/stdc++.h>
using namespace std;

int knapsack(int W, vector<int> weights , vector<int> values, int n){
	if(n == 0 or W == 0){
		return 0;
	}

	// If weight of the nth item is more  
	// than Knapsack capacity W, then  
	// this item cannot be included 
	// in the optimal solution  
	else if( W < weights[n-1]){
		return knapsack(W,weights,values,n-1);
	}
	else{
		return max(values[n-1] + knapsack(W-weights[n-1], weights, values,n-1), knapsack(W,weights,values,n-1));
	}
}

int main(){
	int W;
	cin>>W; // max knapsack weight capacity
	int n;
	cin>>n; // number of items
	vector<int > weights(n);  // weight list
 	vector<int > values(n);   // values of coresponding weights
	for(int i = 0; i < n; i++){
		cin>>weights[i];
	}

	for(int i = 0; i < n; i++){
		cin>>values[i];
	}

	cout<<knapsack(W,weights,values,n);
}