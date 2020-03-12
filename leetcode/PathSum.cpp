
/*
Given a binary tree and a sum, determine if the tree 
has a root-to-leaf path such that adding up all 
the values along the path equals the given sum.

*/


class Solution {
public:
    

    
    bool hasPathSum(TreeNode* r, int sum) {

        if(r == nullptr){
            return false;
        }
        sum -= r->val;
        return (r->left==nullptr and r->right==nullptr and sum==0 ) or (hasPathSum(r->left,sum) or hasPathSum(r->right,sum));
    }
};