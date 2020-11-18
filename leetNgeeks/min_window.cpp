

#include<bits/stdc++.h>
using namespace std;






void find_window(string s1,string s2) {
	unordered_map<char,int> hs1,hs2;

	for(auto c:s2){
		hs2[c]++;
	}

	
	int l = 0; // left ptr


	int start = -1;
	int min_len = INT_MAX;
	int count = 0;

	for(int j = 0; j < s1.length(); j++){

		hs1[s1[j]]++;

		// matched char
		if(hs2[s1[j]] != 0 && hs1[s1[j]] <= hs2[s1[j]]){
			count++;
		}

		if(count == s2.length()){

			while(hs1[s1[l]]>hs2[s1[l]] or
					hs2[s1[l]]==0) {

				if(hs1[s1[l]] > hs2[s1[l]]){
					hs1[s1[l]]--;
				}
				l++;
			}

			int len = j - l + 1;
			if(min_len > len){
				min_len = len;
				start = l;
			}
		}


	}

	if(start == -1) cout<<"No window exists\n";

	string ans = "";
	ans = s1.substr(start,min_len);
	/*for(int i = start; i < min_len;i++){
		ans += s1[i];
	}*/
	cout<<"Ans "<<ans<<endl;


}
		





int main() {
	string s1,s2;
	s1 = "this is test string";
	cin>>s2;


	find_window(s1,s2);
}
