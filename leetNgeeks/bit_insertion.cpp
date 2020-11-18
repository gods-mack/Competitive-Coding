// Inserting M into N such that m 
// starts at bit j and ends at bit i 

// https://www.geeksforgeeks.org/inserting-m-into-n-such-that-m-starts-at-bit-j-and-ends-at-bit-i-set-2/

#include<bits/stdc++.h>
using namespace std;

int updateBits(int n,int m,int i,int j){


	bitset<16> bt,bt_n;

	

	for(int b = i; b <= j; b++){
		int x = m%2;
		bt[b] = x;
		cout<<x;
		m = m / 2;
	}
	int N = n;
	for(int i = 0; i < 16; i++){
		bt_n[i] = N%2;
		N = N/2;
	}
	

	for(int b = i; b <= j; b++) {
		bt_n[b] = bt[b];
	}
	
	int ans = 0;
	int p  = 0;
	for(int i = 0; i < 16; i++){
		ans += pow(2,p)*bt_n[i];
		p++;
	}

	//cout<<"val "<<val<<endl;
	cout<<"ans "<<ans<<endl;

	return ans;
}


void updateBits_eff(int n,int m,int i,int j) {

	// make every bit off from o to j
	int clear_mask = -1 << (j+1);

	// cap bits from 0 to i
	int capture_mask = (1<<i) - 1;

	// what before 0 to i
	int captured_bits = n & capture_mask;

	
	m = m << i;

	// clearing bits 0 to j
	n = n&clear_mask;


	n = n|m;
	n = n|captured_bits;

	cout<<n<<endl;
}

int main() {
	int n,m,i,j; cin>>n>>m>>i>>j;

	cout<<updateBits(n,m,i,j)<<endl;

	updateBits_eff(n,m,i,j);
}