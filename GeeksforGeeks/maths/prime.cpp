         // sieve of Eratosthenes Algorithm

//   Given a number n, print all primes smaller 
//   than or equal to n. 
//   It is also given that n is a small number

// timee: O( n * log(logn) )


#include<bits/stdc++.h>
using namespace std;

void prime(int n){

	bool primeTable[n+1];

	memset(primeTable,true,sizeof(primeTable) );

	// true -- > this prime
	// flase -- > not prime

	for(int i = 2; i*i<=n; i++){
		
		if(primeTable[i] == true){

			for(int j = i*i; j<=n; j = j + i){
				primeTable[j] = false;
			}
		}
	}

	for(int p = 2; p <=n; p++){
		if(primeTable[p]){
			cout<<p<<" ";
		}
	}

	
}



int main(){
	int n; cin>>n;
	prime(n);


}