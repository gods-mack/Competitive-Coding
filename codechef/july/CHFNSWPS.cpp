#include<bits/stdc++.h>
#define SIZE 1e9
using namespace std;

//vector<long int> matr(1000000008);



int main(){
   ios_base::sync_with_stdio(false);
    cin.tie(NULL);


   int t; cin>>t;

   while(t--) {
      int n; cin>>n;
      vector<int> a(n);
      vector<int> b(n);
      map<long int,int> amap;
      map<long int,int> bmap;
      set<long int> st;
      for(int i = 0; i < n; i++) {
         cin>>a[i];
         amap[a[i]]++;
         st.insert(a[i]);
      }
      for(int i = 0; i < n; i++) {
         cin>>b[i];
         bmap[b[i]]++;
         st.insert(b[i]);
      }

      int flag = 0;
      long int matr = 1000000008;
      vector<long int> tmp;

      for(auto it=st.begin();it!=st.end();++it){
         int x,y;
      if(*it<matr)
        matr=*it;
      x  = amap[*it];
      y = bmap[*it];
         long int tt = abs(x-y);
      // cout<<tt<<endl;
         if(tt%2 == 0){
         // tt = abs(x-y);
            for(int i = 0; i < tt/2; i++){
               tmp.push_back(*it);
            }
         }
         else{
            flag = 1;
         }
      }
      if(flag == 1){
         cout<<-1<<"\n";
      }
      else{
         long int res = 0;
         int l = tmp.size();
         sort(tmp.begin(),tmp.end());
         int i = 0;
         while(i<l){
            res += min(2*matr, min(tmp[l-1],tmp[i]) );
            i++;
            l--;
         }
         cout<<res<<"\n";
      }
   }
}
