

// Easy
// https://leetcode.com/problems/same-tree/

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
    
        if(p==nullptr and q==nullptr){
            return true;
        }
        
        if(p && q && p->val==q->val){
    
        
            return (isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
        }
        return false;
            
    }
};