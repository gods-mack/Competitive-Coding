
#include<bits/stdc++.h>
using namespace std;



vector<string> ans;


void sol(int n,string tmp,int op,int cl){

	if(op < cl){
		return;
	}
	if(op==n and cl==n){
		ans.push_back(tmp);
		cout<<"ans "<<tmp<<endl;
		return ;

	}
	if(op == n and cl < n) { // for e.g "((())"
		tmp += ')';
		sol(n,tmp,op,cl+1);


	}
	if(op < n and cl < n) {
		sol(n, tmp+"(", op+1, cl);
		sol(n, tmp+")", op, cl+1);
	} 
}

int main() {
	int n; cin>>n;
	
	string tmp = "(";
	sol(n,tmp,1,0);

}