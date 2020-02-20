
// SPOJ = https://www.spoj.com/problems/FACTCG2/

// prime factorization in O( log(N) )

#include<bits/stdc++.h>
#define MaxNum 10000007
using namespace std;


vector<int> primeTable(MaxNum,0);

void sieve(){
	primeTable[0] = primeTable[1] = 1;

	for(int i = 2; i*i<=primeTable.size(); i++){
		if(primeTable[i] == 0){
			for(int j = i*i; j<=primeTable.size(); j+=i){
				if(primeTable[j] == 0){
					primeTable[j] = i;
				}
			}
		}
	}

	/*for(int i = 0; i < primeTable.size(); i++){
		if(primeTable[i]){
			cout<<i<<" ";
		}
	}*/
}

void primeFactor(int n){

	printf("1 x");
	while(primeTable[n]!=0 and n%primeTable[n] == 0){
			
		printf(" %d x",primeTable[n]);
		if(primeTable[n] == 0)
			break;
		n = n/primeTable[n];
	}
	printf(" %d\n",n);
}

int main(){
	
	sieve();
	int n;
	while(scanf("%d",&n) == 1)
		if(n == 1){
			printf("1\n");
			continue;
		}
		else primeFactor(n);

}