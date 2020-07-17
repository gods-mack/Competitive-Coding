

#include<bits/stdc++.h>
using namespace std;

int digCount(long int n) {

	int count = 0;

	while(n > 0) {
		count += n%10;
		n = n/10;
	}

	return count;
}

int main() {
	int t; cin>>t;
	while(t--) {
		int n; cin>>n;
		int pa = 0;
		int pb = 0;
		while(n--) {
			long int a; cin>>a;
			long int b; cin>>b;
			int wa, wb ;
			if(a/10 != 0 or a==10) {
				wa = digCount(a);
			}
			else {
				wa = a;
			}
			if(b/10 != 0 ){
				wb = digCount(b);
			}
			else{
			 	wb = b;
			}
			if(wa > wb) {
				pa++;
			}
			else if(wb > wa) {
				pb++;
			}
			else if(wb == wa) {
				pa++;
				pb++;
			}


		}
		if(pa > pb) {
			cout<<0<<" "<<abs(pa)<<endl;
		}
		else if(pb > pa) {
			cout<<1<<" "<<abs(pb)<<endl;
		}
		else if(pa == pb) {
			cout<<2<<" "<<pa<<endl;
		}
	}
}