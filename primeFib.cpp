/*Given a number N, you need to find if N is fibonacci-prime number or not. A fibonacci-prime is any number that is both a prime and a fibonacci number.*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
 int n,count=0;
 cin>>n;
 
  int a1=5*n*n-4;
  int a2=5*n*n+4;
   int x;
     x = sqrt(a1);
         int y=sqrt(a2);
 for(int i=2;i<n/2;i++)
 { if(n%i==0)
   { count++; }
 }

  if((x*x==a1 || y*y==a2) && count==0 )
  {  cout<<"YES"<<endl;
  }
  else
   {  cout<<"NO"<<endl;
    }
}
