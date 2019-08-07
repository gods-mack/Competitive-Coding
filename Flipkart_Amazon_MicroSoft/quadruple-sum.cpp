/*
Given an array A of size N, find all combination of four elements in the array whose sum is 
equal to a given value K. For example, if the given array is {10, 2, 3, 4, 5, 9, 7, 8} and K = 23, 
one of the quadruple is “3 5 7 8” (3 + 5 + 7 + 8 = 23).

The output should contain only unique quadrples  For example, if input array is {1, 1, 1, 1, 1, 1} and K = 4
then output should be only one quadrple {1, 1, 1, 1}


Example:
Input:
2
5 3
0 0 2 1 1 
7 23
10 2 3 4 5 7 8

Output:
0 0 1 2 $
2 3 8 10 $2 4 7 10 $3 5 7 8 $

*/




#include<bits/stdc++.h>
using namespace std;

void getFour(vector<int> a, int sum){
    
   sort(a.begin(), a.end());
  
   int n = a.size();
  // map< pair<int,int> , pair<int,int> > has;       
   
    int flag  = -1;
    
    for(int i = 0; i < n -3; i++){
        if (i > 0 and a[i-1] == a[i]) continue;
        for(int j = i + 1; j < n-2; j++){
            if(j > i + 1 and a[j-1] == a[j]) continue;
            int l = j + 1;
            int r = n - 1;
            
            while(l  < r){
                if(a[i] + a[j] + a[l] +a[r]  == sum){
                    cout<<a[i]<<" "<<a[j]<<" "<<a[l]<<" "<<a[r]<<" $";
                    flag = 1;
                    l = l + 1;
                    r =  r - 1;
                    while (l < r and a[l] == a[l-1])
                    { l++ ; }
                    while (l < r and a[r] == a[r+1]) 
                    {  r --;  }
                }
                else if(a[i] + a[j] + a[l] +a[r]  < sum){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        
    }

    
    if(flag == -1){
        cout<<"-1 ";
    }
}
int main(){
    int T; cin>>T;
    while(T--){
        int n;
        cin>>n; int sum;
        cin>>sum;
        vector<int> a(n);
        for(int i = 0; i< n; i++){
            cin>>a[i];
        }
        getFour(a,sum);
        cout<<endl;
    }
}