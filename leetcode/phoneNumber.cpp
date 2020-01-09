


// phone number combination

#include<bits/stdc++.h>
using namespace std;

void dfs(map<int,string> phone,int start,vector<string> &res, string digits,string curr){
	
	if(curr.length() == digits.length()  and !digits.empty()){ // When one combination completes intert it in res vector
		res.push_back(curr);
		return;
	}

	for(int i = start; i < (int)digits.length(); i++){

		for(char c : phone[digits[i] - '0']){
			dfs(phone,i+1,res,digits,curr+c);
		}
	}
}


void combinations(string digits){

	map<int,string> phone;
	phone[1] = "";
	phone[2] = "abc";
	phone[3] = "def";
	phone[4] = "ghi";
	phone[5] = "jkl";
	phone[6] = "mno";
	phone[7] = "pqrs";
	phone[8] = "tuv";
	phone[9] = "wxyz";
	
	vector<string> res;

	dfs(phone,0,res,digits,"");

	for(int i = 0; i < (res).size(); i++){

		string s = res[i];
		cout<<s<<endl;
	}

}


int main(){
	string num;
	cin>>num;

	combinations(num);
}