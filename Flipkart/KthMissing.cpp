// Given an increasing sequence a[], 
// we need to find the K-th missing contiguous 
// element in the increasing sequence which is not 
// present in the sequence. If no k-th missing element is there output -1.

// Input : a[] = {2, 3, 5, 9, 10};   
//        k = 1;
// Output : 4
// Explanation: Missing Element in the increasing 
// sequence are {4, 6, 7, 8}. So k-th missing element
// is 4

// input: a[] = [2,4,10,7], k = 5
// output : 9

#include<iostream>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;


void find(vector<int> &arr,int k,int arrSize){

   sort(arr.begin(),arr.end()); // sort the array

   int maxElement = *max_element(arr.begin(),arr.end());  // find maximum Element from array
   int minElement = *min_element(arr.begin(),arr.end());  // find minimum Element from array

   int sum=0;
   for(int j=0;j<arrSize-1;j++){
       sum = sum + (abs(arr[j+1]-arr[j])-1 );
   
       if(sum>=k){
           int ans=arr[j+1] - abs(k-sum);
           cout<<ans-1 <<endl;
           break;
       }

   }

} // end function


int main(){
   int arrSize;
   cin>>arrSize;
   vector<int> arr(arrSize);

   for(int i=0;i<arrSize;i++){
       cin>>arr[i]; 
   }
   int k; cin>>k;

  find(arr,k,arrSize);

} // End Main()












