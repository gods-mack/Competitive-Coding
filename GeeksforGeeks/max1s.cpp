

// Given a boolean 2D array, where each row is sorted.
// Find the row with the maximum number of 1s.

#include<bits/stdc++.h>
using namespace std;


int countOne(vector<int> a,int l,int r) {

	if(l <= r) {
		int mid = (l+r)/2;

		if(a[mid] == 1){	
			if(a[mid-1] == 1){
				return countOne(a,l,mid-1);
			}
			else if(a[mid-1] == 0) {
				//cout<<"find "<<a.size()-(mid)<<endl;
				return a.size()-(mid);
			}
		}
		else if(a[mid] == 0){
			if(a[mid+1] == 0){
				return countOne(a,mid+1,r);
			}
			else if(a[mid+1] == 1){
				//cout<<"mid "<<mid<<endl;
				//cout<<"find# "<<a.size()-(mid+1)<<endl;
				return a.size()-(mid+1);
			}
		}
	}
}


// O(MlogN) solution
void maxOnesRow(vector<vector<int>> a, int m, int n) {

	int maxx = INT_MIN;
	int ind;
	for(int  i = 0;  i < m; i++) {
		int tmp = countOne(a[i],0,n-1);
		if(maxx < tmp) {
			maxx = tmp;
			ind = i;
		}
	}
	cout<<"maxx "<<maxx << " ind "<<ind<<endl;
}


// O(M + N) solution
int findRow(int m, int n, vector<vector<int>> a){
    int row = 0;
    int i = 0, j = n - 1;
    while(i < m && j >= 0){
        if(a[i][j] == 1){
            row = i;
            j--;
        }
        else i++;
    }
    return row;
}

int main() {
	int m,n; cin>>m>>n;
	vector<vector<int> > a(m);

	for(int i = 0; i < m; i++) {
		a[i].resize(n);
		for(int j = 0; j < n; j++) {
			cin>>a[i][j];
		}

	}



	//cout<<"ans "<<countOne(a,0,n-1);
	maxOnesRow(a,m,n);
}