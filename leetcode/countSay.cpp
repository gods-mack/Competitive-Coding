// COunt annd say - Easy

#include<bits/stdc++.h>
using namespace std;



void sol(int k) {

	if(k == 1){
		cout<<"1";
		return;
	}

	string s = "1"	;

    k = k - 1; //it was counting 1 extra step
	while(k--) {
		int count = 1;
		string tmp ="";
		int n = s.length();
		for(int i = 0; i < n; i++) {
			if(s[i] == s[i+1]){
				count++;
			}	
			else{
				tmp += count + '0';
			//	cout<<"tmpco "<<tmp<<endl;
				tmp += s[i];
				count = 1;
				//cout<<"tmp: "<<tmp<<endl;
			}
		}

		s = tmp;
	}

	cout<<s;
}

int main() {
	int n;
	cin>>n;

	sol(n);
}