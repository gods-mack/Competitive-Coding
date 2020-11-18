

/*
Minimum characters to be added at front to make
 string palindrome
*/

#include<bits/stdc++.h>
using namespace std;


void sol(string s) {

	int l = 0;
	int r = s.length() - 1;


	int count = 0;

	while(l < r)  {

		if(s[l] == s[r]) {
			l++; r--;
		}
		else  {
			r--;
			count++;
		}
	}

	cout<<"coutn "<<count<<endl;
}

int main() {
	string s; cin>>s;

	sol(s);

}