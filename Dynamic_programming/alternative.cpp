
#include<bits/stdc++.h>

using namespace std;


int sol(vector<int> a, int &ind, int n,int count) {
	if(ind >= n) {
		return 0;
	}

	int res1,res2;
	if(count %2 ==0) {
		ind = ind+1;
		int ind_ = ind + 1;
		res1 = a[ind] - sol(a,ind_,n,count+1);
		int ind__ = ind + 1;
		res2 = sol(a,ind__,n,count+1);
	}
	else{
		int ind_= ind + 1;
		res1 = a[ind] + sol(a,ind_,n,count+1);
		int ind__ = ind + 1;
		res2 = sol(a,ind__,n,count+1);
	}
	cout<<"res1 res2 "<<res1<<" "<<res2<<endl;
	return max(res1,res2);
}

int main() {
	int n; cin>>n;
	vector<int> a(n);
	for(auto &x:a){
		cin>>x;
	}
	int ind = 0;

	int res= sol(a,ind,n,1);
	cout<<"ans "<<res<<	endl;
}