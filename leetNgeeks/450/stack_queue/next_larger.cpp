
#include<bits/stdc++.h>
using namespace std;


void next_larger(vector<int> &a) {

	int n = a.size();
	stack<int> s;

	vector<int> ans(n);
	ans[n-1] = -1;
	s.push(a[n-1]);
	for(int i = n-2; i>= 0; i--) {

		int x = a[i];
		while(  !s.empty() and s.top()<=x ) {
			s.pop();
		}
		if(s.empty()) {
			ans[i] = -1;
		}
		else{
			ans[i] = s.top();
		}
		s.push(x);

	}
	cout<<"ANS\n";
	for(auto x:ans) {
		cout<<x<<" ";
	}
}

int main() {
	int n; cin>>n;
	vector<int> a(n);
	for(auto &x:a){
		cin>>x;
	}

	next_larger(a);

}