
// https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/559/week-1-october-1st-october-7th/3481/


#include<bits/stdc++.h>
using namespace std;


vector<vector<int> > ans;
int cnt = 0;

int demo(int tar,vector<int>a,vector<int> &tmp,int ind) {


	if(tar == 0){
		ans.push_back(tmp);
		return 1;
	}
	if(tar < 0){
		return 0;
	}

	if(ind <= 0 and tar >=1) {
		return 0;
	}


	int sum1 = demo(tar,a,tmp,ind-1);
	tmp.push_back(a[ind-1]);
	int sum2 = demo(tar-a[ind-1],a,tmp,ind);
	tmp.pop_back();	

	return sum2 + sum1;

}



int main() {
	int n; cin>>n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin>>a[i];
	}
	int tar ; cin>>tar;

	vector<int> tmp;

	cout<<demo(tar,a,tmp,n)<<endl;
	cout<<"cnt "<<cnt<<endl;
	for(auto v:ans){
		for(auto x:v){
			cout<<x<<" ";
		}
		cout<<endl;
	}

}