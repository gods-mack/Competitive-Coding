

#include<bits/stdc++.h>
using namespace std;


int main() {
	int m; cin>>m;
	int n; cin>>n;
	int a[m][n];
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			cin>>a[i][j];
		}
	}
	int x; cin>>x;

	int i = 0;
	int j = n-1;

	while(i < m and j>=0) {

		if(a[i][j] == x){
			cout<<"found at "<<i<<" "<<j<<endl;
			break;
		}
		if(a[i][j] > x){
			j--;
		}
		else{
			i++;
		}
	}
}