
// square root of number woth precision


#include<bits/stdc++.h>
using namespace std;


void square_root(int N) {

	// 0 <= root < N

	int l = 0;
	int r = N;
	//int mid;
	float ans;

	while(r >= l) {

		int mid = (l+r)/2;

		if(mid*mid == N) {
			ans = mid;
			break;
		}
		if(mid*mid < N){
			l = mid+1;
			ans = mid;
		}
		else{
			r = mid-1;
		}
	}

	float increment = 0.1;
	for(int i  = 0; i < 3; i++) {

		while(ans*ans <= N) {
			ans += increment;
		}
		ans = ans - increment;
		increment /= 10;
	}
	cout<<"ans "<<ans<<endl;


}

int main() {

	int n; cin>>n;

	square_root(n);


}