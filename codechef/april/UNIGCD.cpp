

// question 4

#include<bits/stdc++.h>
typedef long long int ll;

using namespace std;



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin>>t;

	while(t--){
		int n; cin>>n;

		if( n == 1){
			cout<<1<<"\n";
			cout<<1 << " "<<1<<"\n";
		}
		else if(n == 2){
			cout<<1<<"\n";
			cout<<1<<" "<<2<<"\n";
		}
		else{
			cout<<n/2<<"\n";
		
			cout<<3<<" "<<1<<" "<<2<< " ";
			
			if(n%2 !=0){
				for(int i = 3; i < n+1; i+=1){
					if(i%2 != 0 ){
						cout<<i<<"\n";
					}
					else{
						cout<<2<<" "<<i<<" ";
					}
				}	
			}
			else{
				for(int i = 3; i < n; i+=1){
					if(i%2 != 0 ){
						cout<<i<<"\n";
					}
					else{
						cout<<2<<" "<<i<<" ";
					}
		
				}	
				cout<<1<<" "<<n<<"\n";
			}
		
		}

	}
}

