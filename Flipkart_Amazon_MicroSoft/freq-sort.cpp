/*

Given an array A[] of integers, sort the array according to frequency of elements. 
That is elements that have higher frequency come first. If frequencies of two elements are same, 
then smaller number comes first.

*/



#include<bits/stdc++.h>

using namespace std;
bool cmp(pair<int,int> p1,pair<int,int> p2) {
    if(p1.second == p2.second){
        return p1.first < p2.first;
    }
    return p1.second > p2.second;
}

void freq_SORT(vector<int> &a){
   //sort(a.begin(), a.end());
    map<int, int> has;
    for(auto x: a){
        has[x]++;
    }
    vector<pair<int, int> > mapcopy(has.begin(), has.end());
    sort(mapcopy.begin(), mapcopy.end(), cmp);
   
    for(auto it = mapcopy.begin(); it!= mapcopy.end(); ++it ){
        //cout<<it->first<<" "<<it->second<<endl;
        int count  = it->second;
        for(int i = 0; i < count; i++){
            cout<<it->first<<" ";
        }
    }
   

    
    
}

int main(){
    int T; cin>>T;
    
    while(T--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int  i = 0; i<n; i++){
			cin>>a[i];
		}
		
        freq_SORT(a);
        cout<<endl;
    }
}
