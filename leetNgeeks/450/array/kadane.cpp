


#include<bits/stdc++.h>
using namespace std;


void max_sum(vector<int> &a ) {

	int max_so_far = INT_MIN;
	int curr_max = 0;

	for(int i=0;i<a.size();i++){

		curr_max += a[i];
		if(curr_max > max_so_far) {
			max_so_far = curr_max;
		}

		if(curr_max < 0) {
			curr_max = -1;
		}
	} 

	cout<<max_so_far<<endl;
	
}

int main() {
	int n; cin>>n;
	vector<int> a(n);
	for(auto &x:a)cin>>x;

	rev(a);

	for(auto x:a){
		cout<<x<<" ";
	}
}