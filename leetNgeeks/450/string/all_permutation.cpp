
//  Permutations of a given string 
#include<bits/stdc++.h>
using namespace std;


void demo(string s, int ind) {

	int n = s.length();
	
	if(ind >= n-1) {
		cout<<s<<endl;
		return;
	}

	for(int i = ind; i < n; i++) {
		swap(s[ind],s[i]);
		demo(s,ind+1);
	}
	

}




int main() {
	string s; cin>>s;

	demo(s,0);
}