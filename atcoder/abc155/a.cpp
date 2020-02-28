


#include<bits/stdc++.h>
using namespace std;

string sol(int a,int b,int c){

  if(a==b and b==c and c==a){
  	return "No";
  }

  if(a!=b and b!=c and c!=a){
  	return "No";
  }

  return "Yes";

}
  

int main(){
  int a,b,c;
  cin>>a>>b>>c;
  
  cout<<sol(a,b,c);
}