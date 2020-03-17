


#include<bits/stdc++.h>
using namespace std;



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin>>t;
	while(t--){
		int n; int q;
		cin>>n>>q;
		vector<int> a(n);
		int e = 0; int o = 0;
		for(int i =0 ; i < n; i++){
			cin>>a[i];
			if(__builtin_popcount(a[i])%2 == 0){
				e++;
			}
			else{
				o++;
			}
		}
		//map<int,pair<int,int>> hs;
		
	
		while(q--){
			int p; cin>>p;
			
				
				if(__builtin_popcount(p) % 2 != 0){
					printf("%d %d\n",o,e);
				}
				else{
					printf("%d %d\n",e,o);
				} 
			}
			
			
		}
	}

