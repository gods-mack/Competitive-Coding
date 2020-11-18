
#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	bitset<16> bt;
	int N = n;
	int i = 0;
	while( N>0){
		bt[i++] = N%2;
		N = N/2;
	}

	int ind = 0;
	int val = 0;
	int ans = 0;

	i = 0;
	while(i < n) {
		if(bt[i] == 1){
			val++;
		}
		else{
			if(bt[i+1] == 1){
				int tmp = 0;
				int j = 0;
				while(bt[j]==1){
					tmp++;
					j++;
				}
				ans = max(ans,tmp+val);
			}
			else{
				ans = max(ans,val);
			}
			val = 0;

		}
	}

	cout<<"ans "<<ans<<endl;

}