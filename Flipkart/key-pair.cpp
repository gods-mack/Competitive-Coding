/*

Given an array A of N positive integers and another number X. 
Determine whether or not there exist two elements in A whose sum is exactly X.
Input:
The first line of input contains an integer T denoting the number of test cases. 
The first line of each test case is N and X, N is the size of array. 
The second line of each test case contains N integers representing array elements A[i].

Output:
Print "Yes" if there exist two elements in A whose sum is exactly X, 
else "No" (without quotes).

Example:
Input:
2
6 16
1 4 45 6 10 8
5 10
1 2 4 3 6

Output:
Yes
Yes

*/


#include<bits/stdc++.h>
#include<iostream>
#define MAX 100000
using namespace std;

int main()
{
    int t ; cin>>t;
    
    while(t--)
    {
        int n,x; cin>>n>>x;
        int arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        
        int count[MAX]={0};
        
        for(int i=0;i<n;i++)count[arr[i]]++;
        
        int flag=0;
        for(int i=0;i<n;i++)
        {
            int a=arr[i];
            count[a]--;
            if(x-a>0 && count[x-a]>=1)
            {
                flag=1;
                cout<<"Yes";
                break;
            }
        }
        if(flag==0)
        cout<<"No";
        cout<<endl;
    }
}
