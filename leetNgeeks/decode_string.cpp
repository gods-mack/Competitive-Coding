
// 394. Decode String
// https://leetcode.com/problems/decode-string/

/*
Input: s = "3[a]2[bc]"
Output: "aaabcbc"
*/

#include<bits/stdc++.h>
using namespace std;



namespace my {
	string ans = "";
}

string util(string s,int& ind) {

	string res = "";
	int len = s.length();
	
	for(; ind < len; ind++){
		if(s[ind] == ']'){
		return res;
		}

		if(s[ind]>='a'&&s[ind]<='z'
			 || s[ind]>='A'&&s[ind]<='Z'){
			res += s[ind];
		}
		else if(s[ind]>='1'&&s[ind]<='9'){
			int times = 0;
			

            while(s[ind]>='0'&&s[ind]<='9'){
                times = times*10 + (s[ind]-'0');
                ind++;
            }

			string tmp = util(s,ind);
			while(times--){
				res += tmp;
			}

		}
		

	}
	
	return res;
}


string decodeString(string s) {
        
	int len = s.length();
	string ans ;
	string tmp = "";
	int ind = 0;
	ans = util(s,ind);

	return ans;
}
int main(){ 

	string s;
	cin>>s;
	cout<<decodeString(s)<<endl;
}