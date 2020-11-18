
	/*
	Smallest window in a string containing all 
	the characters of another string 

	*/

// https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1

#include<bits/stdc++.h>
using namespace std;



void sol(string s, string p) {

	unordered_map<char,int> mp, mp_p;
	unordered_set<char> st,st1;
	for(auto c:p) {
		st.insert(c);
		mp_p[c]++;
	}
	


	int count = 0;
	int start = 0;
	int end ;
	int min_length = INT_MAX;
	int st_index = 0;
	for(int i = 0; i < s.length(); i++) {

		mp[s[i]]++;



		// first intial window
		if(st.find(s[i]) != st.end()) {
			count++;
			st.erase(s[i]);
		}


		if(count == p.length()) {

		
			
			while(mp_p[s[start]]==0 or mp[s[start]] > mp_p[s[start]] ){

				if(mp[s[start]] > mp_p[s[start]])
					mp[s[start]]--;
				start++;
				
			}
			
			if(min_length > (i-start+1)) {
				min_length = i-start + 1;
				st_index = start;
				end = i;
			}
		}
		
	}

	cout<<"answer:\n";
	cout<<s.substr(st_index, min_length);

}

int main() {
	string s;
	cin>>s;
	string p; cin>>p;

	sol(s,p);
}