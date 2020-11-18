


#include <bits/stdc++.h>
using namespace std;


/*
void demo(bector<int> a, int ind) {



}*/


int main() {
	int n; cin>>n;
	vector<int> a(n);
	for(auto &x:a) {
		cin>>x;
	}


	//unordered_set<int> st;
	set<int> st;
	int sum = 0;
	for(int i = 0; i < n; i++) {
		sum  = 0;
		for(int j = i; j < n; j++) {
			sum += a[j];
			st.insert(sum);
			cout<<"sum "<<sum<<endl;
		}
	}


	cout<<"dis\n";
	for(auto it:st){
		cout<<it<<" ";
	}



}