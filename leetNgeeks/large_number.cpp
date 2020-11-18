
#include<bits/stdc++.h>
using namespace std;



int digit(int num) {
	int count = 0;
	int n = num;

	while(n != 0) {
		n = n/10;
		count++;
	}

	return count;

}

bool cmp(int a,int b) {

	string s1 = to_string(a);
	string s2 = to_string(b);

	string s1s2 = s1+s2;
	string s2s1 = s2+s1;
	if(s2s1 < s1s2) {
		return true;
	}
	return false;
}

int main() {

	int t; cin>>t;
	while(t--) {
		int n; cin>>n;
		vector<int> a(n);
		for(int i = 0; i < n; i++) {
			cin>>a[i];
		}

		sort(a.begin(),a.end(),cmp);

		for(int i = 0; i < n; i++) {
			cout<<a[i];
		}
		cout<<endl;

	}
}