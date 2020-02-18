/* SPOJ AMR11E- Distinct prime

Lucky Numbers are those positive integers 
that have at least three distinct prime factors; 30 and 42 are the first two. 
Malfoy's teacher has given them a positive integer n, 

*/

#include<bits/stdc++.h>
using namespace std;


void findPrime(int n){

	int counter = 0;
	int k = 30;   // first lucky number

	while(counter != n){

		bool primeTable[k+1];
		memset(primeTable,true,sizeof(primeTable));

		for(int i = 2; i*i <= k; i++){
			if(primeTable[i]){
				for(int j = i*i; j <= k; j = j + i){
					primeTable[j] = false;
				}	
			}
		}

		int count = 0; // count three distinct prime
		for(int i = 2; i < sizeof(primeTable); i++){
			// check is it factor and prime
			if(primeTable[i] and k%i == 0){
					count++;
			}
		}

		if(count>=3){
			counter++;
		}
		if(counter == n){
			break;
		}
		k++;

	}
	cout<<k<<endl;
}

int main(){
	int t; cin>>t;
	while(t--){
		int n;
		cin>>n;

		findPrime( n);
	}
}