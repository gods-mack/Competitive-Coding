/*
COIN CHANGE MAKING PROBLEM  [ TOP DOWN SOLUTION (recursive exponential)]

Given a value V, if we want to make change for V cents, and we have infinite supply of each of C = { C1, C2, .. , Cm} valued coins, what is the minimum number of coins to make the change?

Examples:

Input: coins[] = {25, 10, 5}, V = 30
Output: Minimum 2 coins required
We can use one coin of 25 cents and one of 5 cents 

Input: coins[] = {9, 6, 5, 1}, V = 11
Output: Minimum 2 coins required
We can use one coin of 6 cents and 1 coin of 5 cents
*/

#include<bits/stdc++.h>
using namespace std;


int minCoins(vector<int> coins, int m , int  amount){

	if( amount == 0){
		return 0;
	}
	int result = INT_MAX;
	for(int i = 0; i < m; i++){
		if(coins[i] <= amount){
			int tmp_res = minCoins(coins, m, amount-coins[i]);
			if(tmp_res != INT_MAX and tmp_res+1 < result){
				result = tmp_res + 1;
			}
		}
	}

	return result;

}

int main(){
	int m;  // size of coin array
	cin>>m; 
	vector<int> coins(m);
	for(int i = 0; i < m ; i++){
		cin>>coins[i];
	}
	int amount; // amount to make
	cin>> amount;

	cout<<minCoins(coins,m,amount);
}


