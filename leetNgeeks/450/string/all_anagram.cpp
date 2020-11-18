

// https://practice.geeksforgeeks.org/problems/print-anagrams-together/1

//  Print Anagrams Together 

#include<bits/stdc++.h>
using namespace std;


void all_anagrams(vector<string> &strs) {

	unordered_map<string, vector<string>> mp;


	for(auto s:strs) {

		string tmp = s;
		sort(s.begin(),s.end());
		mp[s].push_back(tmp);
	}


	for(auto v:mp) {
		for(auto x:v.second) {
			cout<<x<<" ";
		}
		cout<<endl;
	}
	
}

int main() {
	int n; cin>>n;
	vector<string> strs(n);
	for(auto &s:strs) {
		cin>>s;
	}


	all_anagrams(strs);

}