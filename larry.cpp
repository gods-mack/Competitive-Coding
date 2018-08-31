#include<bits/stdc++.h>
using namespace std;

int main()
{
	 int n,count=0;
	  cin>>n;
	  vector<int> a(n);
	  for(int i=0;i<n;i++)
	   {cin>>a[i]; }
	   
	   for(int j=0;j<n-1;j++)
	   { for(int k=j+1;k<n;k++)
		    { 
				  if(a[j]>a[k])
				   {count++; }
		     }
	   }
	   
	   if(count%2==0)
	   {cout<<"YES"; }
	   else
	   { cout<<"NO"; }
   }	     		   
