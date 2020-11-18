
#include <cstdio>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define pb push_back
using namespace std;

vector<long long int>a,b;

int main() {
    int g;
    cin>>g;
    for(int i=0;i<g;i++){
        long long int n,m,x,cnt=0,mx=0,tmp,c;
        cin>>n>>m>>x;
        a.pb(0);
        for(int j=1;j<=n;j++){
            cin>>c;
            cnt+=c;
            a.pb(cnt);
        }
        cnt=0;
        b.pb(0);
        for(int j=1;j<=m;j++){
            cin>>c;
            cnt+=c;
            b.pb(cnt);
        }
        for(int j=0;j<=n;j++){
            //cout<<a[j]<<" ";
            if(a[j]<=x){
            tmp=j;
            tmp+=upper_bound(b.begin(),b.end(),x-a[j])-b.begin()-1;
            //cout<<j<<" "<<tmp<<endl;
            mx=max(tmp,mx);
            //cout<<"max "<<mx<<" i "<<j<<" x-aj "<<x-a[j]<<endl;
            }
        }
        a.clear();b.clear();
        cout<<mx<<endl;
    }
    
    return 0;
}
