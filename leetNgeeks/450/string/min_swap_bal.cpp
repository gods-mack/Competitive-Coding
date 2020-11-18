

// https://practice.geeksforgeeks.org/problems/minimum-swaps-for-bracket-balancing/0
//  Minimum Swaps for Bracket Balancing 

#include<bits/stdc++.h>
using namespace std;


void min_swap(string s) {

	int count = 0 ;
	int sum = 0;
	int n = s.length();


	vector<int> pos;

	for(int i = 0; i < n; i++) {
		if(s[i] == '[') {
			pos.push_back(i);
		}
 	}
 	int p = 0;

	for(int i = 0; i < s.length(); i++) {

		if(s[i] == '[') {
			++count;
			p++;
		} 
		else if(s[i] == ']') {
			--count;
		}

		if(count < 0) {

			sum += pos[p] - i;
		/*	while(j < n and s[j] != '[') {
				j++;
			}*/
			swap(s[i],s[pos[p]]);
			p++;
			cout<<"now "<<s<<endl;
			count = 1;
			//sum += j-i;
		} 

	}


	cout<<"sum " << sum << endl;
	cout<<"len "<<n<<endl;

}
	
int main() {
	string s; cin>>s;

	min_swap(s);
}