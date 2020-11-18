//  Largest Substring Between Two Equal Characters

/*
Input: s = "abca"
Output: 2
Explanation: The optimal substring here is "bc".
*/

#include<bits/stdc++.h>
using namespace std;



void demo(string s,int l,int r,int &count) {

	if(r < l) {
		return ;
	}
	if(s[l] == s[r]) {
		if((r-l) > count) {
			count = r-l;
		}
	}

	demo(s,l+1,r,count);
	demo(s,l,r-1,count);


}

int main() {
	string s;
	cin>>s;

	int l = 0;
	int r = s.length()-1;
	int count =0 ;

	demo(s,l,r,count);


	cout<<"count "<<count<<endl;


}