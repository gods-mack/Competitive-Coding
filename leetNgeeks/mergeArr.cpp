

#include<bits/stdc++.h> 
using namespace std; 



void sol(vector<int> &a,vector<int> &b,int m,int n){

	int i = m-1;
	int j = 0;

	while(i >= 0 and j < n) {

		if(a[i] > b[j]){
			int tmp = a[i];
			a[i] = b[j];
			b[j] = tmp;
			i--;
			j++;

		}
		else{
			break;

		}
		
	}
	cout<<"eee\n";

	sort(a.begin(),a.end());
	sort(b.begin(),b.end());

	for(int i = 0; i < m; i++) {
		cout<<a[i]<<" ";
	}
	for(int i = 0; i < n; i++) {
		cout<<b[i]<<" ";
	}



}

int main() {


	int m; cin>>m;
	int n; cin>>n;
	vector<int> a(m);
	vector<int> b(n);
	for(int i = 0; i < m; i++) {
		cin>>a[i];
	}

	for(int i = 0; i < n; i++) {
		cin>>b[i];
	}

	sol(a,b,m,n);


}
