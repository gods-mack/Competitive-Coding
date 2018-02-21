#include<bits/stdc++.h>
using namespace std;
int main()
{  int s,t,a,b,m,n,ap=0,on=0; 
 cin>>s>>t; cin>>a>>b; cin>>m>>n; int app[m],orn[n];
  for(int i=0;i<m;i++)
  { cin >>app[i]; }
 for(int j=0;j<n;j++)
 {  cin>>orn[j]; }

  for(int e=0;e<m;e++)
  {  if((a+app[e]>=s) && (a+app[e]<=t))
     { ap++; }
  }
  for(int r=0;r<n;r++)
  {
    if((b+orn[r]>=s) && (b+orn[r]<=t))
    {
      on++; }
 }
  //cout<<"apples : "<<ap<<" "<<"orange : "<<on<<endl;
 cout<<ap<<endl;
 cout<<on;
} 
