
#include<bits/stdc++.h>
using namespace std;


// 2nd method
    int findDuplicate(vector<int>& a) {
        
        int n = a.size();
        for(int i = 0; i < n; i++) {
            
            
           
            if(a[abs(a[i])] > 0) {
                a[abs(a[i])] = a[abs(a[i])] * -1;
            }
            else{
                return abs(a[i]);
            }
        }
        
        return -1;
    }




//1 ist method
int main() {
	int n; cin>>n;
	vector<int> a(n);
	for(auto &x:a) {
		cin>>x;
	}

	sort(a.begin(),a.end());

	for(int i = 0; i < n-1; i++) {
		if(a[i] == a[i+1]){
			cout<<a[i]<<" ";
			break;
		}
	}


}