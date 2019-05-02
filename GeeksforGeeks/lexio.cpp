#include<iostream>
#include<cstring>
using namespace std;

int main()
{
string s; cin>>s;
int k; cin>>k;
int n=s.length();
char t[n];
int last=0;int new_last=0;int size=0;int count=0;

for(char ch='z';ch>='a';ch--)
{ count=0;

for(int i=0;i<n;i++)
{
 if(s[i]==ch)
 { count++; }
}

if(count>=k)
{
 for(int i=last;i<n;i++)
 {  if(s[i]==ch)
   { 
     t[size++]=ch;
     new_last=i;
   }
 }
}
last=new_last;
}

t[size]='\0';

cout<<t<<endl;

}







