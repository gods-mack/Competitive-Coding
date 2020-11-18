

/*Given an array of numbers find all such 
triplets that satisfy the given condition.Condition: 
a[i] < a[j] < a[k] where I < j < k.

*/

#include<bits/stdc++.h>
using namespace std;


void sol(vector<int> a) {

	vector<int> maxx(a.size());
	vector<int> minn(a.size());


	int minvalue = a[0];
	int maxvalue = a[a.size()-1];	

	for(int i = 0; i < a.size(); i++) {
		if(i == 0) {
			minn[i] = -1;
		}
		else{
			if(minvalue >= a[i]) {
				minvalue  = a[i];
				minn[i] = -1;
			}
			else{
				minn[i] = minvalue;
			}
		}
	}
	for(int i = a.size()-1; i>=0; i--) {
		if(i == a.size()-1) {
			maxx[i] = -1;
		}
		else{
			if(maxvalue <= a[i]) {
				maxvalue  = a[i];
				maxx[i] = -1;
			}
			else{
				maxx[i] = maxvalue;
			}
		}
	}

	for(auto x:minn) {
		cout<<x<<" ";
	}
	cout<<"\n";
	for(auto x:maxx) {
		cout<<x<<" ";
	}
	cout<<endl;
	int flag = 0;
	for(int i = 0; i < a.size(); i++) {
		if(maxx[i] != -1 and minn[i]!=-1){
			flag = 1;
			break;
		}
	}
	if(flag){
		cout<<1<<endl;
	}
	
}


int main() {
	int n; cin>>n;
	vector<int> a(n);
	for(auto &x:a){
		cin>>x;

	}
	sol(a);
}