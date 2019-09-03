
/*
The stock span problem is a financial problem where we have a series of n daily price 
quotes for a stock and we need to calculate span of stock’s price for all n days.
The span Si of the stock’s price on a given day i is defined as the maximum number 
of consecutive days just before the given day, for which the price of the stock on 
the current day is less than or equal to its price on the given day.
For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, 
then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}

Example: 
price[100,65,70,120,80,90]
output:
[1,1,2,4,1,2]

*/



#include<bits/stdc++.h>
using namespace std;

void stockSpan(vector<int> stocks){
	int n = stocks.size();
	vector<int> ans(n);
	stack<int> st;
	st.push(0); // first index of elemnt
	ans[0] = 1;

	for(int i = 1; i < n; i++){

		while(!st.empty() and stocks[st.top()] <= stocks[i]){
			st.pop();
		}

		if(st.empty()){
			ans[i] = i + 1;
		}
		else{
			ans[i] = i - st.top();
		}

		st.push(i);
	}

	// print ans

	for(auto x : ans){
		cout<<x<<" ";
	}	
}


int main(){
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		std::vector<int> stocks(n);
		for(int i = 0; i < n ; i++){
			cin>>stocks[i];
		}
		stockSpan(stocks);
		cout<<endl;
	}
}
