

#include<bits/stdc++.h>
using namespace std;

void sol(priority_queue<int> a, priority_queue<int> b,int n){

	int maX = INT_MIN;
	for(int i = 0; i < n; i++){
		if(a.top() < b.top()){
			a.pop(); b.pop();
			//maX = INT_MIN;
		}
		
	}

	if(a.empty() or b.empty()){
		cout<<"YES\n";
	}
	else{
		cout<<"NO\n";
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin>>t;
	int s; cin>>s;
	while(t--){
		if(s == 1){
			int n; cin>>n;
			priority_queue<int> a;
			for(int i = 0; i < n; i++){
				int x; cin>>x;
				a.push(x);
			}
			priority_queue<int> b;
			for(int i = 0; i < n; i++){
				int x; cin>>x;
				b.push(x);
			}

			sol(a,b,n);

		}
	}
}