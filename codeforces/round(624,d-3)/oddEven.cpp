

#include<bits/stdc++.h>
using namespace std;



int sol(long long int a, long long int b){

	if(a==b){
		return 0;
	}
	else if(a>b){
		if(abs(a-b)%2 == 0){
			return 1;
		}
		else{
			return 2;
		}
	}
	else{
		if(abs(a-b) % 2 == 0){
			return 2;
		}
		else{
			return 1;
		}
		
	}


	
}

int main(){

	int t; cin>>t;
	while(t--){
		long long int a,b; cin>>a>>b;

		cout<<sol(a,b)<<endl;
	}
}