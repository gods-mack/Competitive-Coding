
// Split the binary string into substrings 
//with equal number of 0s and 1s


	#include<bits/stdc++.h>
using namespace std;


void split_(string s) {

	int count_0 = 0;
	int count_1 = 0;

	int n = s.length();
	int i = 0;
	int count = 0;

	while(i < n) {

		if(s[i] == '0') {
			count_0++;
		}
		else{
			count_1++;

		}
		if(count_0 == count_1){
			count++;
		}
		i++;

	}

	cout<<count<<endl;
}

int main() {
	string s; cin>>s;
	
	split_(s);

}