
// Easy
// https://leetcode.com/problems/invert-binary-tree/

class Solution {
public:
    
    void helper(TreeNode* root){
        
        if(root==nullptr){
            return ;
        }
        
        if(root->left){
            auto tmp = root->left;
            auto right_side = root->right;
            root->left = root->right;
            root->right = tmp;
            
        }
        else{
            auto tmp = root->right;
            auto left_side = root->left;
            root->right = root->left;
            root->left = tmp;
        }
        helper(root->right);
        helper(root->left);
    }
    
    TreeNode* invertTree(TreeNode* root) {
        TreeNode *rt = root;
        helper(rt);
        
        return root;
        
    }
};