// You are given an array arr[] of N integers including 0. T
// The task is to find the smallest positive number missing from the array.
// Note: Expected solution in O(n) time using constant extra space.

// Smallest Positive missing number 


#include<bits/stdc++.h>
using namespace std;


int findSol(vector<int> a, int n){
   
   map<int,int> mpp;
   for(auto x: a){
       mpp[x]++;
   }
  if(mpp.find(1) == mpp.end()){
      return 1;
  }
   
   for(auto itr = mpp.begin(); itr != mpp.end(); ++itr){
   		if(mpp.find(itr->first+1) == mpp.end() and itr->first >= 0 ){
   			return itr->first + 1;
   		}
   }
   
   return a[n-1]+1;
   
}

int main(){

   int t;
   cin>>t;
   while(t--){
       int n;
       cin>>n;
       vector<int> a(n);
       for(int i = 0 ; i < n; i++){
           cin>>a[i];
       }
       cout<<findSol(a,n)<<endl;
       
   }
    
}

