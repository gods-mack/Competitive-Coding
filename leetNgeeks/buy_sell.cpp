#include<bits/stdc++.h>
using namespace std;



void sol(vector<int> a,int n) {

}


void bforce(vector<int> a,int n){
	int ul = 0;

	int i = 0;
	while(i < n){
		int st = i;
		int flag = 0;
		int end;
		int f2 = 0;
		for(int j = i; j < n; j++) {
			if(a[j] < a[j+1]){
				flag = 1;
				f2 = 1;
			}
			else{
				f2 = 0;
				end = j;
				i = j+1;
				break;
			}
			if(j == n-1) { // if it goes till last
				if(f2) { end = n -1 ; i = n + 1;}
			}

		}
	
		if(flag == 1){
		    if(st == end){ // same buy and sell day
		        continue;
		    }
			cout<<"("<<st<<" "<<end<<")"<<" ";
			ul = 1;
		}
		
	}
	if(ul == 0){
		cout<<"No Profit";
	}
}

int main() {
	int t; cin>>t;
	while(t--) {
		int n; cin>>n;
		vector<int>a(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
		}

		bforce(a,n);
		cout<<endl;
		//ssol(a,n);
	}
}