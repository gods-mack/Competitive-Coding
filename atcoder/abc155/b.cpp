// B - Papers, Please

/*
You are an immigration officer in the Kingdom of AtCoder. 
The document carried by an immigrant has some number of 
integers written on it, and you need to check whether they meet
certain criteria.

According to the regulation, the immigrant should be 
allowed entry to the kingdom if and only if the following
 condition is satisfied:

    All even numbers written on the document are divisible 
    by 3 or 5


If the immigrant should be allowed entry according 
to the regulation, output APPROVED; otherwise, print DENIED.
*/

#include<bits/stdc++.h>
using namespace std;

string sol(vector<int> &a,int n){

	for(auto x:a){
		if(x%2 == 0){
			if(x%3 != 0 and x%5 != 0){
				return "DENIED";
			}
		}
	}
	return "APPROVED";
}

int main(){
	int n; cin>>n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}

	cout<<sol(a,n);
}