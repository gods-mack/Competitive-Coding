

// Print all subsequences of a string
// https://www.geeksforgeeks.org/print-subsequences-string/

#include<bits/stdc++.h>
using namespace std;



vector<string> subseq;
void all_subseq(string s,string ans) {

	int n = s.length();
	if(n == 0) {
		subseq.push_back(ans);
		return ;
	}

	all_subseq(s.substr(1),ans+s[0]);
	all_subseq(s.substr(1),ans);
}

int main() {
	string s;
	cin>>s;


	all_subseq(s,"");

	for(auto x:subseq) {
		cout<<x<<endl;
	}

}