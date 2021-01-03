
//  Transform to Sum Tree 

// https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1#

int util(Node *root) {

	if(root == nullptr){
		return 0;
	}
	if(root->left == nullptr and root->right==nullptr){
	    int val=root->data;
		root->data = 0;
		return val;
	}
	
    int val = root->data;
    
	root->data =  util(root->left) + util(root->right);
	
	return val+root->data;
	
}

void toSumTree(Node *node)
{
    // Your code here
    int ans = util(node);
}