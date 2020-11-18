

#include<bits/stdc++.h>
using namespace std;


void second_most_repeated(vector<string> a) {

	unordered_set<string		> st;
	string s1;
	string s2;
	int n = a.size() ;

	for(int i=n-1; i>=0; i--) {

		if(st.find(a[i]) == st.end())  {
			st.insert(a[i]);
		}
		else{
			s2  = s1;
			s1 = a[i];
		}
	}

	cout<<"second most repeated string "<<s2<<endl;
}

int main() {
	int n; cin>>n;
	vector<string> a(n);
	for(auto &x:a)cin>>x;

	second_most_repeated(a);
}