

 // finf those triple whose sum is zero
// a + b + c = 0




#include<bits/stdc++.h>
using namespace std;


 // using hasing (N^2)
void tripletSum(vector<int> &a){

	int n = (int)a.size();
	sort(a.begin(),a.end());

	//set<int> hash;
	
	cout<<endl;	

	for(int i = 0; i < n ; i++){
		int aa = a[i];
		unordered_set<int> hash;
		for(int j = i+1; j < n; j++){
			int b = a[j];
			
		
			int c = (aa+b);
			c = -c;
			if(hash.find(c) != hash.end() ){

				cout<<aa<<" "<<b<<" "<<c<<" "<<endl;
			}
			else{
				hash.insert(b);
			}

			
		}
	}
}

// using pointer technique (N^2)
void pntr(vector<int> &a){

	int n = (int)a.size();
	vector<vector<int > > sets;
	sort(a.begin(), a.end());

	for(int i = 0; i  < n ; i++){

		int l = i + 1;
		int r = n -1 ;
		int aa = a[i];
		while(l  < r){	
			int b = a[l];
			int c = a[r];

			if((b+c) == -aa){
				l++;
				//cout<<aa<<" "<<b<<" "<<c<<endl;
				sets.push_back({aa,b,c});
			}
			else if((b+c) > -aa){
				r--;
			}
			else{
				l++;
			}

		}
	}	

	for(int i = 0; i < (int)sets.size(); i++){
		for(int j = 0; j < (int)sets[i].size(); j++){
			cout<<sets[i][j]<< " ";
		}
		cout<<endl;
	}
}


int main(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i =0; i < n; i++){
		cin>>a[i];
	}

	tripletSum(a);  // hashing solution
	pntr(a);        // two pointer solution
}
