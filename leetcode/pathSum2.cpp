
// https://leetcode.com/problems/path-sum-ii/

/*
Given a binary tree and a sum, find all root-to-leaf paths 
where each path's sum equals the given sum.


*/

class Solution {
public:
    
    void util(vector<int>tmp,vector<vector<int>>&ans,TreeNode *root,int sum){
	
	if(root == nullptr){
		return;
	}

	tmp.push_back(root->val);
	//cout<<root->data<<" ";
	sum -= root->val;
	
	if (root->left==NULL && root->right==NULL && sum==0  ){

		ans.push_back(tmp);

	 }
	 util(tmp,ans,root->left,sum);
	 util(tmp,ans,root->right,sum);
		
	
}

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
	    vector<int> tmp;
	    util(tmp,ans,root,sum);
        return ans;
	
    }
};