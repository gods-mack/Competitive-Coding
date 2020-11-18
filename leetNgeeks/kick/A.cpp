

#include<bits/stdc++.h>
using namespace std;

int main(){
	int t; cin>>t;
	for(int tt=1;tt<=t;tt++){
		int n; cin>>n;
		int a[n];
		for(int i = 0; i < n; i++) {
			cin>>a[i];
		}

		int ans = 0;
		for(int i = 0; i < n; i++) {
			int tmp = 0;
			int diff;
			for(int j = i; j < n-1; j++) {
				if(j == i) {
					diff = a[j+1]-a[j];	
					tmp++;
				}
				else{
					if(a[j+1]-a[j] == diff) {
						tmp++;
					}
					else{
						break;
					}
				}
			}
			ans = max(ans,tmp);
		}
	
		cout<<"#"<<tt<<": "<<ans+1<<endl; 
	}

}