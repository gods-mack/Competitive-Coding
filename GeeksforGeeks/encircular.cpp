
// https://www.geeksforgeeks.org/check-if-a-given-sequence-of-moves-for-a-robot-is-circular-or-not/




#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
#define N 0 
#define E 1 
#define S 2 
#define W 3 



vector<string> doesCircleExist(vector<string> path) {

   
   vector<string> ans;
  
 for(int j  = 0; j< path.size(); j++){
      int x = 0, y = 0; 
      int dir = N; 
  for (int i=0; path[j][i]; i++) 
  { 
      // current move 
      char move = path[j][i]; 
  
      // If move is left or right, then change direction 
      if (move == 'R') 
        dir = (dir + 1)%4; 
      else if (move == 'L') 
        dir = (4 + dir - 1)%4; 
  
     
      else // if ('G') 
      { 
         if (dir == N) 
            y++; 
         else if (dir == E) 
            x++; 
         else if (dir == S) 
            y--; 
         else // dir == W 
            x--; 
      } 
  
  }

  if((x == 0 && y == 0)){
      ans.push_back("YES");
  } 
  else{
      ans.push_back("NO");
  }

 } //  for

 return ans;
}

int main(){
    int n;
    cin>>n;

    vector<string > vec(n);

    for(int i = 0; i <n; i++){
        string s;
        cin>>s;
        vec[i] = s;
    }
    vector<string> res = doesCircleExist(vec);

    for(int i = 0; i <res.size(); i++){
        cout<<res[i]<<endl;
    }

}
