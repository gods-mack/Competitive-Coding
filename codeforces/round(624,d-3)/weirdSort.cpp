
#include<bits/stdc++.h>
using namespace std;


string sol(int a[], int p[],int n,int m){

	map<int,int>  hash;

	for(int i = 0; i < m; i++){
		hash[p[i]-1]++;
	}

	for(int i = 0; i < n; i++){

		for(int j = 0; j < n; j++){
			if(a[j] > a[j+1] and hash[j] ){
				//swap(&a[j],a[j+1]);
				int tmp  = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
			}
		}
	}

	int flag = 1;

	for (int i = 0; i < n - 1; ++i) {
			flag &= a[i] <= a[i + 1];
	}

	if(flag){ return "YES"; }
	else{ return "NO"; } 

	
}

int main(){
	int t; cin>>t;
	while(t--){ 
		int n;
		int m;
		cin>>n>>m;
		int a[n];
		int p[m];
		for(int i = 0; i < n; i++) { cin>>a[i]; } 
		for(int i = 0; i < m; i++) { cin>>p[i]; } 

		cout<<sol(a,p,n,m)<<endl;
	}
}