

#include<iostream>
using namespace std;
int main()
{
int n,a,high=0,c; cin>>n;
 for(int i=0;i<n;i++)
 {
   cin>>a;
  if(a>high)
 {  high = a;
     c=0;}
  if(high==a)
  { c++; 

  }
 }
 return c;   
}
