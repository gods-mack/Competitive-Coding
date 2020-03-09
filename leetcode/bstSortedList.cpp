
// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

// Convert Sorted Array to Binary Search Tree
class Solution {
public:
    
    TreeNode* sol(vector<int>&in,int start,int end){

    if(start > end){
        return NULL;
    }
    int mid = (start + end) / 2;

    TreeNode *newnode = new TreeNode(in[mid]);
    if(start == end){
        return newnode;
    }

    newnode->left = sol(in,start,mid-1);
    newnode->right = sol(in,mid+1,end);

    return newnode;
}
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
            int n = nums.size();
           return sol(nums,0,n-1);
    }
};