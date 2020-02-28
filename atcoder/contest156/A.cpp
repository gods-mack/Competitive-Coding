
#include<bits/stdc++.h>
using namespace std;

int main(){
  int c; cin>>c;
  int r; cin>>r;
  
  if(c>=10){
    cout<<r;
  }
  else{
    int inr = 100*(10 - c);
    inr += r;
    cout<<inr;
  }
  
}


