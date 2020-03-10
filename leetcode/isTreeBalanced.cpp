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
    

    int height(TreeNode *root){

	if(root == nullptr){
		return 0;
	}
	
	int l = height(root->left);
	int r = height(root->right);
	
	if(l>r){
		return l+1;
	}
	else{
		return r + 1;
	}
}
    
    
    
bool isBalanced(TreeNode *root){
   if(root == nullptr){
		return true;
	}
	int l = height(root->left);
	int r = height(root->right);
	
	if(abs(l-r)<=1 and isBalanced(root->left) and isBalanced(root->right) ){
		return true;
	}
	
	return false;
}
};