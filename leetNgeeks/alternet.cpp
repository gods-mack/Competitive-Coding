

 //Rearrange Array Alternately 

#include<bits/stdc++.h>
using namespace std;


void sol(vector<int> &a) {
    
    
    
	int n = a.size();
	if(n == 1) {
	    cout<<a[0]<<" "<<endl;
	    return;
	}
	int mx = n-1;
	int mn = 0;

	while(1) {

		cout<<a[mx]<<" ";
		cout<<a[mn]<<" ";
		mx--;
		mn++;
		if(n%2 == 0 and mx < mn){
			break;
		}
		if(n%2 != 0  and mx == mn){
			cout<<a[mx]<<" ";
			break;	
		}
	}

	cout<<endl;
}

int main() {

    int t; cin>>t;
    while(t--) {
        
    
	int n; cin>>n;

	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin>>a[i];
	}
	sol(a);
	
    }


}