

#include<bits/stdc++.h> 
using namespace std; 

void sol(vector<int> &a,vector<int> &b) {

	int m = a.size();
	int n = b.size();

	sort(a.begin(),a.end());
	sort(b.begin(),b.end());


	int res = 0;

	for(int i = 0; i < m; i++) {

		 if(a[i] == 1){
			continue;
		}
		for(int j = 0; j < n; j++) {

			if(b[j] == 1 ){
				res++;
			}
			else if(b[j] > a[i]){
				res++;
			}
		
		}
	}

	//cout<<"res "<<res<<endl;
	cout<<res<<endl;



}



int main() {


	int m; cin>>m;
	int n; cin>>n;
	vector<int> x(m);
	vector<int> y(n);


	for(int i = 0; i<m; i++) {
		cin>>x[i];
	}
	for(int i = 0; i<n; i++) {
		cin>>y[i];
	}

	sol(x,y);

}