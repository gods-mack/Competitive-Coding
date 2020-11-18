

// https://leetcode.com/problems/combination-sum-ii/
// 40. Combination Sum II

#include<bits/stdc++.h>
using namespace std;


namespace my {
	vector<vector<int>> ans;
	set<vector<int>> set_ans_;

}

int util(vector<int> & a, int tar,int ind,vector<int> &tmp) {



	if(tar == 0) {
		//sort(tmp.begin(),tmp.end());
		my::set_ans_.insert(tmp);
		return 1;
	}

	if(tar < 0 ) {
		return 0;
	}
	if(tar >= 1 and ind <= 0) {	
		return 0;
	}

	int sum1 = util(a,tar,ind-1,tmp);
	tmp.push_back(a[ind-1]);
	int sum2 = util(a,tar-a[ind-1],ind-1,tmp);
	tmp.pop_back();

	return sum1 + sum2;

} 

void  combinationSum2(vector<int>& a, int target) {

	/*unordered_set<int> tmp_a;
	for(auto x:arr) {
		tmp_a.insert(x);
	}
	vector<int> a;
	for(auto it:tmp_a){
		a.push_back(it);
	}
	*/
        vector<int> tmp;
        int rs = util(a,target,a.size(),tmp);


       for(auto t:my::set_ans_){
        	my::ans.push_back(t);
        }

       	for(auto x:my::ans) {
       		for(auto xx:x){
       			cout<<xx<<" ";
       		}
       		cout<<endl;
       	}
} 


int main(){ 
	int n; cin>>n;
	vector<int> a(n);
	for(auto &x:a) {
		cin>>x;
	}

	int tar; cin>>tar;

	combinationSum2(a,tar);


}