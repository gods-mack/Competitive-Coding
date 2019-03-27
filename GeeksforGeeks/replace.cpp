
// Given an array of positive and negative elements. 
// The task is to replace every i-th element of the array by the 
// absolute difference of absolute sums of positive and negative elements in the range i+1 to N. That is, 
// find the absolute sum of all positive elements and 
// the absolute sum of all negative elements in the
// range i+1 to N. Now find the absolute difference of 
// these two sums and replace with the i-th element.


//Note: The last element of the updated array will be zero

// Input : N = 5,  arr[] = {1, -1, 2, 3, -2}
// Output : arr[] = {2, 3, 1, 2, 0}

// Input : N = 6,  arr[] = {-3, -4, -2, 5, 1, -2}
// Output : arr[] = {2, 2, 4, 1, 2, 0}.



#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(){
   int n;
   cin>>n;
   vector<int> a(n);
   for(int i=0;i<n;i++){
     cin>>a[i];
    }
   int pos_sum=0;
   int neg_sum=0;
   int diff = 0;
   
    for (int i = n - 1; i >= 0; i--) { 
  
        // calculate differenbce of both sums 
        diff = abs(pos_sum) - abs(neg_sum); 
  
        // if i-th element is positive, 
        // add it to positive sum 
        if (a[i] > 0) 
            pos_sum += a[i]; 
  
        // if i-th element is negative, 
        // add it to negative sum 
        else
            neg_sum += a[i]; 
  
        // replace i-th elements with 
        // absolute difference 
        a[i] = abs(diff); 
    } 
 // print Output :
cout<<" output : "<<endl;
  for(int m=0;m<n;m++){
    cout<<a[m]<<" ";
  }
   

}
 
   
