
// https://leetcode.com/problems/minimum-depth-of-binary-tree/

// 111. Minimum Depth of Binary Tree

class Solution {
public:
    
    int height(TreeNode *root){
        if(root == nullptr){
            return 0;
        }
        //ans++;
        int l,r;
        
            l  = height(root->left);
        

            r = height(root->right);
        if(l==0){
            return 1 + r;
        }
        else if(r==0){
            return 1 + l;
        }
        return 1 + min(l,r);
    }
    
    int minDepth(TreeNode* root) {
        
        int ans = 0;
        ans = height(root);
        
        return ans;
        
    }
};