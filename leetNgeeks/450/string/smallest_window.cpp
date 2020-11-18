

// Smallest distinct window 

// https://practice.geeksforgeeks.org/problems/smallest-distant-window/0


#include	<bits/stdc++.h>
using namespace std;


void smallest_window(string s) {

	unordered_set<char> st;
	unordered_map<char,int> mp;
 	for(char c:s) {
 		mp[c]++;
		st.insert(c);
	}

	int n = s.length();
	int min_length = INT_MAX;
	int f = 1;



	int l = 0;
	int r = n-1;


 
 	int count = 0;
 	int start = 0;
	for(int i = 0; i < n; i++) {

		if(st.find(s[i]) != st.end()) {
			count++;
			st.erase(s[i]);
		}

		if(count == st.size()) {

			while(mp[s[start]] > 1) {
				if(mp[s[start]] > 1) {
					mp[s[start]]--;
					start++;
				}

			}

		}
	}


}

int main() {
	string s; cin>>s;

	smallest_window(s);
}