

#include<bits/stdc++.h>
using namespace std;

void sol(vector<int> &a,int limit) {



	int i = 0;
	int n = a.size();

	while(i < n) {

		int curr = i;
		int space  = 0;
		int start = i;
		int total = a[curr];
		while(total+space <= limit and curr < n){
			curr++;
			total += a[curr];
			space++;
		}
		int end = curr-1;
		cout<<"st end "<<start<<" "<<end<<endl;
		i = curr;
 	}
}

int main() {
	int n;
	cin>>n;
	vector<int> a(n);
	for(auto &x:a) cin>>x;

	int limit; cin>>limit;


	sol(a,limit);	
}