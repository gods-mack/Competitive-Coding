
// 337. House Robber III
// https://leetcode.com/problems/house-robber-iii/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,int> dp;
    int rob(TreeNode* root) {
        
        if(root == nullptr){
            return 0;
        }
        if(dp.find(root) != dp.end()){
            return dp[root];
        }
        
        int sum1 =0;
        sum1 += rob(root->left);
        sum1 += rob(root->right);
        
        int sum2 = 0;
        
        sum2 += root->val;
        if(root->left){
            sum2 += rob(root->left->left);
            sum2 += rob(root->left->right);
        }
        if(root->right){
            sum2 += rob(root->right->left);
            sum2 += rob(root->right->right);
        }
        
        dp[root] = max(sum1,sum2);
        return max(sum1,sum2);
    }
};