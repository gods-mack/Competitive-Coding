
/*
url : https://practice.geeksforgeeks.org/problems/swapping-pairs-make-sum-equal/0

Given two arrays of integers, write a program to check i
f a pair of values (one value from each array) exists such 
that swapping the elements of the pair will make the sum of two arrays equal.
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
                    //has.insert(make_pair( make_pair(a[i],a[j]),make_pair(a[l],a[r]) ));
                    flag = 1;
                    l = l + 1;
                    r =  r - 1;
                    while (l < r and a[l] == a[l-1]) l++;
                    while (l < r and a[r] == a[r+1]) r--;
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
