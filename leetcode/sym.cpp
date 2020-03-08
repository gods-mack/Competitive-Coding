// https://leetcode.com/problems/symmetric-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    bool check(TreeNode* r1,TreeNode *r2){
        if(r1==nullptr and r2==nullptr){
            return true;
        }
        if(r1 && r2 and (r1->val==r2->val)){
            return check(r1->left,r2->right) and check(r1->right,r2->left);
        }
        return false;
    }
    
    bool isSymmetric(TreeNode* root) {
        return check(root,root);
    }
};