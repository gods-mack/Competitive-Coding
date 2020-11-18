#include<bits/stdc++.h>
using namespace std;



void dem(int a,int b){
	swap(a,b);
}

void permute(string s,int l,int r){
	
	if(l==r){
		cout<<s<<endl;
		//l++;
	}
	

	
	for(int i = l; i <= r; i++){
		swap(s[l],s[i]);
		permute(s,l+1,r);
		//swap(s[l],s[i]);
	}	
}



int main() {
	string s;
	cin>>s;
	sort(s.begin(),s.end());
	cout<<s<<endl<<endl;
	int l = 0;
	int r = s.length() - 1;
	permute(s,l,r);
}
