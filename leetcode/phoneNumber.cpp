


// phone number combination

#include<bits/stdc++.h>
using namespace std;

void combinations(string num){

	map<int,string> phone;
	phone[2] = "abc";
	phone[3] = "def";
	phone[4] = "ghi";
	phone[5] = "jkl";
	phone[6] = "mno";
	phone[7] = "pqrs";
	phone[8] = "tuv";
	phone[9] = "wxyz";
	
	for(int i = 0; i < (int)num.length(); i++){
		string base = phone[i];

		for(int )
	}
}

int main(){
	string num;
	cin>>num;

	combinations(num);
}