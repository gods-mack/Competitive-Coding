

// Mutilpy two binary string 
/*

string s1 = "1100"
string s2 = "1010"

OUTPUT = 120
*/

#include<bits/stdc++.h>
using namespace std;

int multiplication(string s1, string s2){

	int num1  = 0; int num2 = 0;
	float count = 0.5;

	for(int i = s1.length() - 1; i>= 0; i--){
		count = count * 2;
		num1 += (s1[i]-'0')*count;
	}
	count = 0.5;
	for(int i = s2.length() - 1; i>= 0; i--){
		count  = count * 2;
	
		int ele = s2[i] - '0';
		num2 = num2  + (ele*count);
		
	}
	

	return num1*num2;
}

int main(){

	int T; cin>>T;
	while(T--){
		string s1, s2; cin>>s1>>s2;
		cout<<multiplication(s1,s2);

	}

}
