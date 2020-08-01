
// Binary Tree Right Side View

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr){
            return ans;
        }
        
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int siz = q.size();
            
            for(int i = 0; i < siz; i++) {
                if(i == siz-1) {
                    TreeNode *curr = q.front();
                    ans.push_back(curr->val); 
                    q.pop();
                    if(curr->left) {
                        q.push(curr->left);
                    }
                    if(curr->right) {
                        q.push(curr->right);
                    }
                }
                else{
                    TreeNode *curr = q.front();
                    q.pop();
                    if(curr->left) {
                        q.push(curr->left);
                    }
                    if(curr->right) {
                        q.push(curr->right);
                    }
                }
            }
                    
            
        } 
        
        return ans;
    }
    
};