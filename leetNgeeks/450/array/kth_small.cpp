#include<bits/stdc++.h>
using namespace std;


int kthsmall(vector<int> &a,int k) {
	
	int n = (int)a.size();


	int minn = *min_element(a.begin(), a.end());
	int maxx = *max_element(a.begin(), a.end());
	vector<int> has(maxx+1,0);
	for(auto x:a){
		has[x]++;
	}

	int count = 0;

	for(int i = minn; i <= maxx; i++) {
		if(has[i] >= 1){
		    
			count += has[i];
		//	count++
		}
		if(count >= k){
		//	cout<<"kth elem "<<i<<endl;
			return i;
			break;
		}
	}
	
	return -1;



}

int main(){

    int t; cin>>t;
    while(t--) {
  int n; cin>>n;
  vector<int> a(n);

  for(int i = 0; i < n; i++) {
    cin>>a[i];
  }
    int k; cin>>k;
  cout<<kthsmall(a, k)<<endl;
    }

}

  


 
