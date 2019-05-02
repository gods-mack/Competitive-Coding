/*Given an array A of N integers,
 *  classify it as being Good Bad or Average.
 *  It is called Good, if it contains exactly X 
 * distinct integers, Bad if it contains less than 
 * X distinct integers and Average if it contain
 * s more than X distinct integers. */
/*

SAMPLE INPUT
                         
4
4 1
1 4 2 5 Avg
4 2
4 2 1 5 AVG
4 3
5 2 4 1 AVG
4 4
1 2 4 5 GOOD
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
 int t; cin>>t;
 
  
 for(int i=0;i<t;i++)
 {
       int n,k; cin>>n>>k; set<int> s;
        vector<int> a(n);
     for(int j=0;j<n;j++)
      { cin>>a[j]; }
  
      for(int m=0;m<n;m++)
       { s.insert(a[m]); }


    if(s.size()==k)
   { cout<<"Good"<<endl; }
     if(s.size()>k)
     { cout<<"Average"<<endl; }
    if(s.size()<k)
      { cout<<"Bad"<<endl; }
}
}












