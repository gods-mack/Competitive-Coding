#include<iostream>
#include<cstring>
using namespace std;

void rescue(int n,char* s)
{

if(s[0][0]=='p')
{
  for(int i=0;i<n/2;i++)
   {  cout<<"LEFT"<<endl; }
 for(int j=0;j<n/2;j++)
   { cout<<"UP"<<endl; }

 }

if(s[0][(n/2)*2]=='p')
{
  for(int i=0;i<n/2;i++)
   {  cout<<"RIGHT"<<endl; }
 for(int j=0;j<n/2;j++)
   { cout<<"UP"<<endl; }
}
if(s[(n/2)*2][0]=='p')
{
 for(int i=0;i<n/2;i++)
   {  cout<<"DOWN"<<endl; }
 for(int j=0;j<n/2;j++)
   { cout<<"LEFT"<<endl; }

}
if(s[(n/2)*2][(n/2)*2]=='p')
{
 for(int i=0;i<n/2;i++)
   {  cout<<"DOWN"<<endl; }
 for(int j=0;j<n/2;j++)
   { cout<<"RIGHT"<<endl; }

}




}


int main()
{
  int m; cin>>m;
  char s[m][m];
  for(int i=0;i<m;i++) {
    for(int j=0;j<m;j++) {
       cin>>s[i][j]; }   }


rescue(m,s);

return 0;
}
