// A C++ Program to play tic-tac-toe 

#include<bits/stdc++.h> 
#include <iostream> 
#include <unordered_map> 
using namespace std; 

vector<string> ans;


void dfs(string s, string curr,int ind,int l,unordered_map<int,string> &mp) {
   
    
    
    if(ind > l) {
        return ;
    }
     //cout<<"curr "<<curr<<endl;
        
	
	if(ind == l){
		if(curr.length() == l){
	    	cout<<"compl "<<curr<<endl;
			ans.push_back(curr);
		}
		return;
	}
	
	for(int i = ind; i < (int)s.length(); i++){

		string tmp = mp[s[i]-'0'];
		for(int j = 0; j < (int)tmp.length(); j++){
			curr += tmp[j];
			dfs(s,curr,i+1,l,mp);
			curr.pop_back();
		}
		//curr.pop_back();
	}
	
	
	
}

int main() {
	unordered_map<int, string> mp; 
  
    // inserting values by using [] operator 
    //mp[1] = "";
	mp[2] = "abc";
	mp[3] = "def";
	mp[4] = "ghi";
	mp[5] = "jkl";
mp[6] = "mno";
mp[7] = "pqrs";
mp[8] = "tuv";
mp[9] = "wxyz";

	string s;
	cin>>s;
	int l = s.length();
	
	string tmp = mp[s[0]-'0'];
	
	for(int i = 0; i < tmp.length(); i++) {
		string t = "";
		t += tmp[i];
		dfs(s,t,1, l,mp);
	}
	

	for(auto x:ans){
		cout<<x<<endl;
	}
	
}
