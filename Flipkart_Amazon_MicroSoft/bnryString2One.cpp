/*
// https://www.geeksforgeeks.org/number-of-steps-required-to-convert-a-binary-number-to-one/

Given a binary string str, the task is to print the numbers of 
steps required to convert it to one by the following operations:

    1. If ‘S’ is odd add 1 to it.
    2. If ‘S’ is even divide it by 2.
*/

#include<bits/stdc++.h>
using namespace std;

string add(string s,int n){
	//cout<<"forADDING "<<s<<" "<<n<<endl;
	string tmp = "";
	int carry=0;
	tmp.push_back('0');
	carry = 1;
	for(int i=n-1;i>=0;i--){
		if(s[i]=='1'){
			if(carry){
				tmp.push_back('0');
				carry = 1;
			}
			else{
				tmp.push_back('1');
			}
		}
		else{
			if(carry){ tmp.push_back('1'); }
			else{ tmp.push_back('0') ;}
			carry = 0;
		}
	}
	if(carry){tmp.push_back('1'); }
	reverse(tmp.begin(),tmp.end());
	//cout<<"revOUT "<<tmp<<endl;
	return tmp;
}

void sol(string s){
	int n = s.size() - 1;
	int count = 0;

	while(n!=0){
		if(s[n]=='1'){
			s = add(s,n);
			n = s.size() - 1;
		}
		else{
			n--;
		}
		count++;
	}
	cout<<"count "<<count<<endl;
}

int main(){
	string s;
	cin>>s;

	sol(s);
}