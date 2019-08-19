
/*
Given an array of numbers, return true if given array can represent 
preorder traversal of a Binary Search Tree, else return false. Expected time complexity is O(n)
*/





#include<bits/stdc++.h>
using namespace std;

string ispreOrderExist(std::vector<int> pre, int n){

	int root = INT_MIN;
	stack<int> s;

	for(int i = 0; i < n; i++){

		if(pre[i] < root){
			return "NO";
		}

		while(!s.empty() and s.top() < pre[i]){
			root = s.top();
			s.pop();
		}

		s.push(pre[i]);
	}

	return "YES";
}

int main(){
	int n; cin>>n;
	vector<int> pre(n);
	for(int i = 0; i < n; i++){
		cin>>pre[i];
	}

	cout<<ispreOrderExist(pre, n)<<endl;
}
