

#include<bits/stdc++.h>
using namespace std;



int edit(string s1,string s2,int i,int j) {

	if(i == 0) {
		return j;
	}


	if(j == 0) {
		return i;
	}

	if(s1[i-1] == s2[j-1]) {
		return edit(s1,s2,i-1,j-1);
	}

	else{
		

		return 1 + 
				min(
					edit(s1,s2,i-1,j-1),   // replace
				min(edit(s1,s2,i-1,j), // remove
					edit(s1,s2,i,j-1))  // insert
				);
	}
}

int main() {
	string s1,s2; cin>>s1>>s2;


	int m = s1.length();
	int n = s2.length();

	cout<<edit(s1, s2, m, n)<<endl;

}