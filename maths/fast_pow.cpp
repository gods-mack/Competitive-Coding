#include<bits/stdc++.h>
using namespace std;

int fastPower(int a, int b){
	int res = 1;
	
	while(b > 0){
		if( (b&1) != 0) {
			res = res * a;
		}

		a = a * a;
		b = b >> 1; 
	}
	return res;
}

int main() {
    int m=5,n=2;
    cout<<fastPower(m,n);
}