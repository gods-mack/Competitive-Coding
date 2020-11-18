#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vector<int> a(n);
        for(auto &x:a) cin>>x;
        
        unordered_map<int,int> mp;
        int sum = 0;
        int f = 0;
        for(auto x:a) {
            sum += x;
            mp[sum]++;
            if(mp[sum] > 1 or sum == 0) {
                f =  1;
                cout<<"Yes\n";
              //  continue;
                break;
            }
        }
        
        if(!f)
            cout<<"No\n";
        
    
    }
    
}