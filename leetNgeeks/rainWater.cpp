
#include<bits/stdc++.h>
using namespace std;


int demo(vector<int> &a,int l,int r){

	if(abs(l-r) <= 1){
		return 0;
	}
	else if(abs(l-r) == 2){
		int val = min(a[l],a[r]);
		int res = a[l+1]-val;
		if(res <= 0){ return 0;}
		else{ return res; }
	}
	else{
		return max(demo(a,l+1,r),demo(a,l,r-1));
	}
}


void sol(vector<int> a, int n) {


	int l_max = 0 ;
	int r_max = 0;
	int l = 0;
	int r = n -1 ;
	int ans = 0;

	while(l <= r){

		if(a[l] < a[r]) {
			if(l_max <= a[l] ){
				//cout<<"l_max was "<<a[l_max]<<endl;
				l_max = a[l];
				//
				//cout<<"now l_max "<<a[l_max]<<" "<<a[l]<<endl;
				l++;
			}
			else{
				ans += l_max-a[l];
				l++;
			}

		}
		else {
			if(r_max < a[r]){
				r_max = a[r];
				r--;
			}
			else{
				ans += r_max - a[r];
				r--;
			}

		}
	}

	//cout<<"ans "<<ans<<endl;
	cout<<ans<<endl;
}

void stacl_sol(vector<int> a,int n){

	stack<int> s;
	s.push(a[0]);
	int curr = a[0];
	int ans = 0;

	for(int i = 1; i < n; i++) {
		if(a[i] > curr or i==n-1){
			int val;
			if(curr > a[i]){
				val = a[i];
			}
			else{
				val = curr;
			}
			cout<<"val came "<<val<<endl;
			while(!s.empty()){

				cout<<"it beacme.. "<<ans<<endl;
				if(val>s.top()){ ans += abs(s.top()-val); }
				s.pop();
			}
			curr = a[i];
			s.push(curr);
		}
		else{
			s.push(a[i]);
		}

	}

	cout<<"ans "<<ans<<endl;
}


void bf(vector<int> &a,int n){

	int res  = 0;

	for(int i = 0; i < n; i++ ){

		int tmp = 0;
		for(int j = i; j < n; j++) {
			if(a[j] <= a[i]){
				tmp += a[i]-a[j];
			}
			else{
				i = j;
				break;

			}
		}
		res += tmp;
	}

	cout<<res<<endl;
}

int main(){
	int t; cin>>t;
	while(t--) {

	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	//cout<<demo(a,0,n-1);
	//bf(a,n);
	//stacl_sol(a,n);
	sol(a,n);
}

	
}