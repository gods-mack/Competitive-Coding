// https://leetcode.com/problems/validate-binary-search-tree/

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
    vector<int> tmp;
    
    void inOrder(TreeNode* tm){
        if(tm==nullptr){
            return;
        }
        inOrder(tm->left);
        tmp.push_back(tm->val);
        inOrder(tm->right);
    }
    
    bool isValidBST(TreeNode* root) {
        
        inOrder(root);
        
        for(int i = 1; i < tmp.size(); i++){
            if(tmp[i] <= tmp[i-1]){
                return false;
            }   
        }
        return true;
    }
};