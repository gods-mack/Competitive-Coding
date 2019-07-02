
// Rotten Oranges problem

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

        
void time_to_rotten(vector<vector<int> > &a,int r,int c){

        
        queue<pair<int,int> > q;  // temp. queue to store rotten orange 
        
        //int count = 0;
        for(int i = 0;i<r; i++){
                for(int j = 0;j<c;j++){
                        if(a[i][j] == 2){
                                q.push(make_pair(i,j));   // intially store rotten oranges in queue
                        }
                    
                }
        }
        int time = 0;
        while(!q.empty()){
                
                int qsize = q.size();
                while(qsize--)
                {
                 
                        pair<int,int> front = q.front();
                        q.pop();
                        int i = front.first;
                        int j = front.second;
                        if(i > 0 and a[i-1][j]==1){
                                a[i-1][j]=2;
                                q.push(make_pair(i-1,j));
                        }
                                
                        if(i < r-1 and a[i+1][j]==1){
                                a[i+1][j]=2;
                                q.push(make_pair(i+1,j));
                        }
                        
                        if(j > 0 and a[i][j-1]==1){
                                a[i][j-1]=2;
                                q.push(make_pair(i,j-1));
                        }
                                
                        if(j < c-1 and a[i][j+1]==1){
                                a[i][j+1]=2;
                                q.push(make_pair(i,j+1));
                        }
                }
                time++;
        }


        
        
        for(int i = 0;i<r; i++){
                for(int j = 0;j<c;j++){
                        if(a[i][j]==1){
                                cout<<-1<<endl;  // if impossible  print -1
                                return;
                        }
                }
        }
        cout<<time-1<<endl;  // print time


} // end of function


int main(){ 
        int t; cin>>t;  // test
    while(t--){    
        
        int r,c;
        cin>>r>>c;
        vector<vector<int> > a(r);
       // vectoor
        for(int i = 0;i<r; i++){
                for(int j = 0;j<c;j++){
                        int x;cin>>x;
                        a[i].push_back(x);
                }
        }


        time_to_rotten(a,r,c);  // call func
        
    }
}
                
		
		


                               
