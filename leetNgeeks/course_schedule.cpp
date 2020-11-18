
// https://leetcode.com/problems/course-schedule/

class Solution {
public:
    
    
    void topo(int u, vector<vector<int> > &g, vector<int> &vis, stack<int> &s,int &f) {
     
        
        vis[u] = 1;
        
        for(int i = 0; i < g[u].size(); i++) {
            if(vis[g[u][i]] == 1) {
                f = 1;
                return;
            }
            if(vis[g[u][i]] != 2) {
                topo(g[u][i], g, vis, s,f);
                 
            }
        }
        vis[u] = 2;
        s.push(u);
        
        
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> g(numCourses);
        
        for(int i = 0; i < prerequisites.size(); i++) {
            
            int x = prerequisites[i][0];
            int y = prerequisites[i][1];
            
            g[x].push_back(y);
        }
        
        vector<int> vis(numCourses, 0);
        stack<int> s;
        int f = 0;
        for(int i = 0; i < numCourses; i++) {
            if(vis[i] == 0){
                topo(i,g,vis,s,f);
                if(f == 1) {
                    return false;
                }
                  
            }
        }
        
      
        return true;
    }
};