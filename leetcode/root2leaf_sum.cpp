
// https://leetcode.com/problems/sum-root-to-leaf-numbers/

/*
Given a binary tree containing digits from 0-9 only, 
each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which
 represents the number 123.

Find the total sum of all root-to-leaf numbers.
*/
class Solution {
public:
    
    int getSum(TreeNode* root,int x ){
         if(root==nullptr){
            return 0;
        }
        if(root->left==nullptr && root->right==nullptr){
            return 10*x + root->val;
        }
        return getSum(root->left,x*10+root->val)+getSum(root->right,x*10+root->val);
    }
    
    int sumNumbers(TreeNode* root) {
       return getSum(root,0);
    }
};