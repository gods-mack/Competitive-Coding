
// question 3
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;


int kFactors(ll n, ll k) 
{ 
    // A vector to store all prime factors of n 
    vector<ll> P; 
  
    // Insert all 2's in vector 
    while (n%2 == 0) 
    { 
        //P.insert(2); 
        P.push_back(2);
        n /= 2; 
    } 
 
    for (ll i=3; i*i<=n; i=i+2) 
    { 
        while (n%i == 0) 
        { 
            n = n/i; 
            P.push_back(2);
        } 
    } 
  
    if (n > 2) {
    	P.push_back(2);
	}
  
    // If size(P) < k, k factors are not possible 
    if (P.size() < k) 
    { 
    	 return -1; 
    } 
    
    return 1;
  
} 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin>>t;


	while(t--){
		ll x;
		ll k; cin>>x>>k;
	
		
		// can we write x using product of k numbers
		if((kFactors(x,k) != -1)){
			cout<<1<<"\n";
			continue;
		}
		else{
			cout<<0<<"\n";
		}


	}
}
