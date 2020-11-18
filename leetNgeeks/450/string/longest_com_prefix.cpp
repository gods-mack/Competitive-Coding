

// https://leetcode.com/problems/longest-common-prefix/

// 14. Longest Common Prefix

#include<bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &strs ) {
	string ans = "";
        
        int m = strs.size();
        int n = strs[0].length();
        if(m ==0|| n==0) {
            return ans;
        }
        
        int i = 0;
        int j = 0;
        
        while(1) {
            i = 0;
            char x = strs[i][j];
            int f = 1;
            while(i < m ) {
                if(strs[i].length() < j+1) {
                    f  = 0;
                    break;
                }
                if(strs[i][j] != x) {
                    f = 0;
                    break;
                }
                i++;
            }
            if(f) {
                ans += x;
            }
            else{
                break;
            }
            cout<<"ans "<<ans<<endl;
            j++;
         }
        
        return ans;
} 
int main() {
	int n; cin>>n;
	vector<string> strs(n);
	for(auto &s:strs) {
		cin>>s;
	}

	cout<<longestCommonPrefix(strs);
}