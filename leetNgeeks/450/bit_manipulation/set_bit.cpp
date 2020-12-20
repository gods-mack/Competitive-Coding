

// count set bit in a number

#include<bits/stdc++.h>
using namespace std;


// other approcah
int set_bit(int N ){

	int count = 0;
	while(N > 0) {
		N = N & (N-1);
		count++;
	}
	return count;
}

int main() {
	int n; cin>>n;
	int count = 0;
	while(n > 0) {
		if(n % 2 == 1) {
			count++;
		}
		n = n / 2;
	}
	cout<<count;
}