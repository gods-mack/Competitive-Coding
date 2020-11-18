
   
    
class Solution {
public:
    

    
    int find_set(vector<int>&p, int v) {
        if(v == p[v]){
            return v;
        }
        return  find_set(p,p[v]);
    }
    
  void  union_set(vector<int> &p, int a,int b) {
        int a_p = find_set(p,a);
        int b_p = find_set(p,b);
        
        if(a_p != b_p)
            p[b_p]  = a_p; 
    }
    
    
    
    
    

    bool equationsPossible(vector<string>& equations) {
         vector<int> parent;
    parent.resize(26);
    //int parent[26];
   
    for(int i=0; i < 26; i++) {
        parent[i] = i;
    }
        
    
        
        
        vector<string> nt_eq;
        
        for(auto e: equations) {
            if(e[1] == '='){ // "=="
                union_set(parent,e[0]-'a' , e[3]-'a');
            }
            else{
                nt_eq.push_back(e);
            }
        }
        
        for(auto nq:nt_eq) {
                
            if(find_set(parent,nq[0]-'a') == find_set(parent,nq[3]-'a')){
                return false;
            }
        }
        
        return true;
    }
};