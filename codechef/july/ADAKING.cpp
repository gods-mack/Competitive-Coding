

#include<bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	while(t--) {
		int k ; cin>>k;
		//char s[8][8];
		string s = "";
		s[0] = 'O';
		k = k - 1;
		for(int i = 1; i < 64; i++) {
			if(k > 0) {
				s[i] = '.';
				k--;
			}
			else{
				s[i] = 'X';
			}

		}

		int m = 0;
		for(int i = 0; i < 8; i++) {
			for(int j = 0; j < 8; j++) {
				cout<<s[m];
				m++;
			}
			cout<<endl;
		}

	}
}